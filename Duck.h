#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;


#ifndef DUCK_DUCK_H
#define DUCK_DUCK_H

/*
 * Утка вид: 'Мраморные чирки', умеет: летать и не знает где она живет, а также имеет
атрибуты: имя, вес, любимое блюдо, форма клюва
Утка вид: 'Мраморные чирки', умеет: плавать и знает где она живет, а также имеет
атрибуты: имя, вес, высота в холке, размер хвоста
Утка вид: 'Лайсанская кряква', умеет: мигрировать (если не поймана, перемещается на
случайное озеро)
 *
 *
 *  Если утка сбежала с фермы и ее
опять поймали и привезли на туже самую ферму, то ей подрезают крылья (если летает)
или вещают груз на лапку (если плавает), и они больше не могут сбежать.
 */

struct Perks {
    Perks() {
        is_swimming = false;
        is_flying = false;
        is_migration = false;
        is_knowing_home = false;
    }

    Perks(bool swim, bool fly, bool migr, bool home){
        is_swimming = swim;
        is_flying = fly;
        is_migration = migr;
        is_knowing_home = home;
    }
    bool is_swimming;
    bool is_flying;
    bool is_migration;
    bool is_knowing_home;

    // for debug
    void stat() const {
        cout << "[ " << is_swimming << is_flying << is_migration << is_knowing_home << "]" << endl;
    }
};

struct Duck {
    Duck() {
        string names[10] = { "Red", "Green", "Blue", "Black", "White", "Рurple", "Brown", "Pink", "Orange", "Yellow" }; // имя утки
        name = names[rand() % 10];
        mass = 2 + rand() % 7;  // вес утки
        type = "default";
    }

    virtual void say() {
        cout << "Привет я утка " << name << "  " << " Вес- " << mass << "КГ" << endl;
    }
    Perks perks{}; // способности утки (плавает/летает/мигрирует/знает_свой_дом)
    string name;
    string lake_name; // дом утки
    string type; // тип утки

    int mass;  // масса утки
    int id{};  // Каждой утке дается уникальный номер id (для деббага)
    vector<string> history_escape; // история утки, на каких фермах она была
};

struct Duck_marble_teals : Duck {
    Duck_marble_teals() {
        string dishes[3] = { "apple", "grass", "ant" }; // еда утки
        favorite_dish = dishes[rand() % 3];
        string shapes[3] = { "long", "short", "average" }; // клюв утки
        beak_shape = shapes[rand() % 3];
        perks.is_flying = true;
        type = "Duck_marble_teals";
    }

    void say() override {
        cout << "Привет я утка " << name << " мой вид - Мраморные чирки и имею следуещее атрибуты:" << endl
             << " Вес- " << mass << "КГ" << endl << " Мое любимое блюдо это: " << favorite_dish << endl << " Форма клюва у меня: " << beak_shape << endl;
    }
    string favorite_dish; // любимое блюдо
    string beak_shape;    //  форма клюва
};


// В задании была опечатка и повторилось название, я назвал Чернобрюхая свистящая утка
struct Black_bellied_Whistling : Duck {
    Black_bellied_Whistling() {
        height_withers = 4 + rand() % 10; //  высота в холке
        tail_size = 4 + rand() % 15; // размер хвоста
        perks.is_knowing_home = true;
        perks.is_swimming = true;
        type = "Black_bellied_Whistling";
    }

    void say() override {
        cout << "Привет я утка " << name << " мой вид - Супер уртка и имею следуещее атрибуты:" << endl
             << " Вес- " << mass << "КГ" << endl << " Высота в холке- " << height_withers << "CМ" << endl << " Размер хвоста- " << tail_size << "CМ"  << endl;
    }
    int height_withers; // высота в холке
    int tail_size;  // размер хвоста
};


struct Duck_laysan_mallard : Duck {
    Duck_laysan_mallard() {
        endurance = rand() % 100; // 0 .. 99
        tail_size = 4 + rand() % 15;
        perks.is_migration = true;
        type = "Duck_laysan_mallard";
    }
    void say() override {
        cout << "Привет я утка " << name << " мой вид - Лайсанская кряква и имею следуещее атрибуты:" << endl
             << " Вес- " << mass << "КГ" << endl << " Выносливость- "  << endurance << "%" << endl << " Размер хвоста- " << tail_size << "CМ" << endl;
    }
    int tail_size; // размер хвоста
    int endurance; // выносливость
};


#endif //DUCK_DUCK_H
