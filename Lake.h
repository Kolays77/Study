#ifndef DUCK_LAKE_H
#define DUCK_LAKE_H


#include <string>
#include <utility>
#include "Duck.h"

struct Counter {
    Counter() {
        swim = 0;
        fly = 0;
        home = 0;
        migration = 0;
    }
    int swim;
    int fly;
    int home;
    int migration;

    void add(shared_ptr<Duck>& duck){
        if(duck->perks.is_flying)
            fly += 1;
        if(duck->perks.is_swimming)
            swim += 1;
        if(duck->perks.is_migration)
            migration += 1;
        if(duck->perks.is_knowing_home)
            home += 1;
    }

    void print_stat() const  {
        cout << endl;
        cout << "Умееют летать :" << fly << endl;
        cout << "Умееют плавать : " << swim << endl;
        cout << "Умееют мигрировать : " << migration << endl;
        cout << "Знают свой дом : " << home << endl << endl;
    }

    void remove(shared_ptr<Duck>& duck) {
        if(duck->perks.is_flying)
            fly -= 1;
        if(duck->perks.is_swimming)
            swim -= 1;
        if(duck->perks.is_migration)
            migration -= 1;
        if(duck->perks.is_knowing_home)
            home -= 1;
    }
};

struct Lake {
    vector<shared_ptr<Duck>> ducks; //вектор умных указателей, чтобы не возникло проблем с очищением памяти из под уток
    string name; // название озера
    Counter counter;
    Lake(string name_, int n) : ducks(n), name(std::move(name_)){
        create_ducks();
    }

    void print_stat(const string& extra="") const  {
        cout << "Статистика по озеру " << name << " " << extra << endl;
        cout << "Всего уток " <<  ducks.size() << endl;
        cout << "Умееют летать :" << counter.fly << endl;
        cout << "Умееют плавать : " << counter.swim << endl;
        cout << "Умееют мигрировать : " << counter.migration << endl;
        cout << "Знают свой дом : " << counter.home << endl << endl;
    }

    // охотнки поймали size_hunt уток,
    // передаем этих уток ферме, а их озера их удаляем (erase)
    vector<shared_ptr<Duck>> get_ducks(int size_hunt){
        if (ducks.empty()) {
            return {};
        }
        vector<shared_ptr<Duck>> hunted_ducks;
        size_hunt = size_hunt < ducks.size() ? size_hunt : int(ducks.size());
        for (int i = 0; i < size_hunt; ++i){
            int index = rand() % int(ducks.size());
            counter.remove(ducks[index]);
            hunted_ducks.push_back(ducks[index]);
            auto temp_size = ducks.size();
            ducks.erase(ducks.begin() + index); // убираем утку с озера
        }
        return hunted_ducks;
    }

    void add_duck(shared_ptr<Duck> duck) { // после побега добавляем утку
        counter.add(duck);
        ducks.push_back(duck);
    }

    void create_ducks() {
        for (int i = 0; i < ducks.size(); ++i) {
            switch (rand() % 3) { // создаем утку определенного вида (всего три вида по задаче)
                case 0:
                    ducks[i] = (shared_ptr<Duck>(new Duck_marble_teals));
                    break;
                case 1:
                    ducks[i] = (shared_ptr<Duck>(new Black_bellied_Whistling));
                    break;
                case 2:
                    ducks[i] = (shared_ptr<Duck>(new Duck_laysan_mallard));
                    break;
            }
            counter.add(ducks[i]);
            if(ducks[i]->perks.is_knowing_home) {
                ducks[i]->lake_name = name;
            }
            ducks[i]->id = i;
        }
    }
};

#endif //DUCK_LAKE_H
