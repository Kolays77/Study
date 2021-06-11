#ifndef DUCK_GAME_H
#define DUCK_GAME_H

#include "Lake.h"
#include "Farm.h"
#include "Duck.h"


struct Game{
    Game(int total_days_, vector<Lake> lakes_, vector<Farm>& farms_) {
        lakes = lakes_;
        farms = farms_;
        curr_day = 0;
        total_days = total_days_;
    }

    bool is_end() const {
        return total_days == curr_day;
    }
    void next_day () {
        curr_day += 1;
        if (curr_day == total_days) {
            cout << "Дни охоты закончились, продолжить охоту?" << endl;
            cout << "Введите 1, чтобы добавить один день" << endl;
            cout << "Введите 2, чтобы законить игру" << endl;
            string command;
            cin >> command;
            if(command == "1") {
                total_days += 1;
            }
        }
    }

    void hunt() {
        for (Farm& farm : farms){
            farm.catch_duck(lakes);
        }
    }

    void lakes_stat(const string& extra="") {
        for (const auto& lake : lakes) {
            lake.print_stat(extra);
        }
    }

    void farms_stat(const string& extra) {
        for (const auto& farm : farms) {
            farm.print_stat(extra);
        }
    }

    void escape() {
        for (Farm& farm : farms) {
            farm.escape(lakes);
        }
    }

    int total_days{};
    int curr_day;
    vector<Lake> lakes;
    vector<Farm> farms;
};


#endif //DUCK_GAME_H
