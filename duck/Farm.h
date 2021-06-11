#ifndef DUCK_FARM_H
#define DUCK_FARM_H

#include "Lake.h"
#include <map>
#include <utility>
/*
 * Добавить сбегание уток с фермы
 * С фермы 'ZUXEGA' могут сбежать утки, которые умеют: плавать и знают где они живут, но в
суматохе попадают на случайное озеро

 С фермы 'YEYUHEX' могут сбежать утки, которые умеют: плавать и знают где они живут, то есть
возвращаются домой

 */

struct Hunter {
    Hunter(int min_,int max_) {
        min = min_;
        max = max_;
    }
    int min, max;
    string name;
    int hunt() const {
        int count = rand() % max + min;
        return count;
    }
};

// ДОБАВИТЬ print_stat (как и у озера)


struct Farm {
    Farm(const string& name_, vector<Hunter> hunters_, Perks perks_, bool random_lake_) {
        perks_escape = perks_;
        hunters = std::move(hunters_);
        name = name_;
        random_lake = random_lake_; // суматоха, утка попадает на случайное озеро
    }

    void print_stat(const string& extra) const{
        cout << "Статистика на ферме " << name << " " << extra <<  endl;
        cout << "Количество уток: " << ducks.size() << endl << endl;
    }

    void catch_duck(vector<Lake>& lakes) {
        int index_lake = rand() % lakes.size();
        for (auto& hunter : hunters) {
            int count_ducks = hunter.hunt();
            if (!lakes[index_lake].ducks.empty()) {
                auto hunted_ducks = lakes[index_lake].get_ducks(count_ducks);
                add_ducks(hunted_ducks); // copy
            }
        }
    }

     bool is_escaping(shared_ptr<Duck>& duck) const {
        if (perks_escape.is_flying && !duck->perks.is_flying) {
            return false;
        }
        if (perks_escape.is_migration && !duck->perks.is_migration) {
            return false;
        }
        if (perks_escape.is_swimming && !duck->perks.is_swimming) {
            return false;
        }
        if (perks_escape.is_knowing_home && !duck->perks.is_knowing_home) {
            return false;
        }
        return true;
    }

    void escape(vector<Lake>& lakes) {
        vector<int> index_escaped_ducks;
        int index;
        if(random_lake) {
            index = rand() % int(lakes.size());
        }

        for (int i; i < ducks.size(); ++i) {
            if (is_escaping(ducks[i])) {
                lakes[index].add_duck(ducks[i]);
                index_escaped_ducks.push_back(i);
            }
        }
        for (int it: index_escaped_ducks){
            ducks.erase(ducks.begin() + it);
        }
    }

    void change_duck_(shared_ptr<Duck>& d) const {
        for (auto& h : d->history_escape){
            if (h == name) {
                if (d->perks.is_flying) {
                    d->perks.is_flying = false; // обрезают крылья
                }
                if (d->perks.is_swimming) {
                    d->perks.is_swimming = false; // вешают грузик
                }
                break;
            }
        }
    }

    //сможет ли она убежать ?
    void add_ducks(vector<shared_ptr<Duck>> ducks_) {
        for (auto& d : ducks_){
            if (!d->history_escape.empty()) {
                change_duck_(d);
                d->history_escape.push_back(name);
            } else {
                d->history_escape.push_back(name);
            }
            ducks.push_back(d);
        }
    }

    Perks perks_escape;
    string name;
    vector<Hunter> hunters;
    vector<shared_ptr<Duck>> ducks;
    bool random_lake;
};

#endif //DUCK_FARM_H
