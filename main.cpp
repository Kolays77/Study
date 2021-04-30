#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <ctime>

#include "Lake.h"
#include "Duck.h"
#include "Farm.h"
#include "Game.h"

using namespace std;

/*
TO-DO
1) Каждое озеро может показать количество уток по умениям на текущий момент
функция печатает в консоль перк - кол-во уток

добавить миграцию (но озеро одно, так что они там и остаются)
ВАРИАНТ #22
В долине озер: 1, уток там живет: 276, а ферм: 2, дней сезона охоты: 6

 ферма yes swim and home
*/

// подсчет кол-во уток определенного типа н оезере

/*Долина диких озер прекрасное место для обитания множества разных видов и мастей
уток. Все утки очень хвастливы и любят рассказывать все о себе, когда их спросят.
Озеро в долине как живой организм знает кто на нем живет, что кто умеет и может об
этом рассказать (сколько уток всего, сколько умеет летать/плавать и т. д.). Но иногда в
долину приходят охотники, на некоторые дикие озера, которые выбирают случайно и
ловят уток, которые там живут один раз в день в течения сезона охоты. Пойманных
уток отвозят на домашнее озеро на ферме. Но уткам не нравится ферма, и каждая
пойманная утка пытается вернуться на свое родное озеро. Если утка сбежала с фермы и ее
опять поймали и привезли на туже самую ферму, то ей подрезают крылья (если летает)
или вещают груз на лапку (если плавает), и они больше не могут сбежать. Также в долине
каждый день может произойти, что-нибудь необычное…
Охотники ловят уток до тех пор, пока на диких озерах не останется ни одной утки, либо
не закончится сезон охоты.

 *
 *В долине в случайном месте (озере или ферме) может появиться: ДискоКряк (Все утки в конце
хода, которые умеют 'крякать', крякают 'ДИСКО') на дней: 4
 *
 */

void print_rules(){
    cout << "help : Распечатать правила" << endl;
    cout << "1 : Cтатистика по озерам" << endl;
    cout << "2 : Cтатистика по фермам" << endl;
    cout << "3 : Перейти к следующему дню" << endl;
}

int main() {
    //SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(NULL));

    const unsigned DAY = 2; // Сколько дней охота
    const unsigned n = 276; // Количесство уток всего

    // Инициализация
    Lake argentino("argentino", n);
    Hunter dan1(2,10);
    Hunter dan2(1, 9);
    Hunter dan3(1, 6);
    Hunter dan4(1, 5);

    Farm zuxega("zuxega",
                {dan1, dan2, dan3, dan4},
                {true, false, false, true}, true);

    Hunter oleg1(1, 5);
    Hunter oleg2(1, 7);
    Hunter oleg3(2, 9);
    Hunter oleg4(2, 8);

    Farm yeyuhex("yeyuhex",
                 { oleg1, oleg2, oleg3, oleg4 },
                 {true, false, false, true}, true);

    vector<Lake> lakes({argentino});
    vector<Farm> farms({zuxega, yeyuhex});
    Game game(DAY-1, lakes, farms);
    string command;

    int super_duck_day = rand() % 7;
    // DEBUG
    /*
    for(int i =0; i < DAY; ++i) {
        game.lakes_stat("до охоты");
        game.farms_stat("до охоты");
        game.hunt();
        game.farms_stat("после охоты");
        game.lakes_stat("после охоты");
        game.escape();
        game.farms_stat("после побега");
        game.lakes_stat("после побега");
    }
    */

    while (true) {
        bool hunted = false;
        bool escaped = false;
        cout << "----------начало дня" << game.curr_day + 1 << "----------" << endl;

        while (!hunted) {
            cout << "1 : Cтатистика по озерам до охоты" << endl;
            cout << "2 : Cтатистика по фермам до охоты" << endl;
            cout << "3 : Начать охоту " << endl;
            cout << "Команда : "; cin>>command; cout << endl;
            if (command == "1")
                game.lakes_stat("До охоты");
            if (command == "2")
                game.farms_stat("До охоты");
            if (command == "3") {
                game.hunt();
                hunted = true;
                cout << "Охотники поохотились" << endl << endl;
            }
        }

        while (true) {
            cout << "1 : Cтатистика по озерам после охоты" << endl;
            cout << "2 : Cтатистика по фермам после охоты" << endl;
            cout << "3 : Перейти к побегу уток с фермы" << endl;
            cout << "Команда : "; cin>>command; cout << endl;
            if (command == "1")
                game.lakes_stat("После охоты");
            if (command == "2")
                game.farms_stat("После охоты");
            if (command == "3") {
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                game.escape();
                cout << "Утки сбежали с ферм на озера" << endl;
                break;
            }
        }

        while(true) {
            cout << "1 : Cтатистика по озерам" << endl;
            cout << "2 : Cтатистика по фермам" << endl;
            cout << "3 : Перейти к завершению дня" << endl;
            cout << "Команда : "; cin>>command; cout << endl;
            if (command == "1")
                game.lakes_stat("После побега");
            if (command == "2")
                game.farms_stat("После побега");
            if (command == "3") {
                cout << "-------Завершение дня " << game.curr_day+1 << "--------" << endl;
                game.next_day();
                if (game.is_end()){
                    cout << "Завершение игры" << endl;
                    return 0;
                }
                break;
            }
        }
    }
    return 0;
}