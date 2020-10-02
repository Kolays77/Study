#include <iostream>
#include "tasks.h"

const std::string source = "tasks.txt";
    
void ExecuteCommand(Tasks& tasks, std::string command) {
    if (command == "add") { 
        std::string section;
        std::string task;
        std::getline(std::cin, section);
        std::getline(std::cin, task);
        tasks.Add(section, task);
    } else if (command == "update") {
        tasks.Update();
    } else if (command == "delete") {
        std::string section;
        std::string task;
        std::cin >> section >> task;
        tasks.Delete(section, task);
    } else if (command == "print") {
        tasks.Print();
    }
}


int main() {
    Tasks tasks(source);
    std::string command;
    std::cin >> command;
    ExecuteCommand(tasks, command);
    return 0;
}