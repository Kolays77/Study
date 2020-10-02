#include <iostream>
#include <utility>
#include <string>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>

#include "english_words.h"



void ProgramInfo() {
    std::cout << "\nThis is a program for saving and repeating English words.\n"
        << "It can be useful in learning English.\n"
        << "When you repeat a word 3 times, this word will have status of 'known word'.\n";
}


void HelpInfo() {    
    std::cout << "\nAllowed commands:\n"
    << "1) To add some words to list word: 'add' 'word1' ... 'wordN'.\n"
    << "2) To show your unknown words: 'show'.\n"
    << "3) To parse some text to dict: 'parse' 'source'.\n"
    << "4) To repeat your unknown words: 'repeat'.\n"
    << "5) To finish a program use: 'exit' OR CTRL+C.\n"
    << "6) To get help type : 'help'.\n\n";
}

void ExecuteCommand (EnglishWords& words, const std::string& comm){
    if (comm == "add"){
        AddWords(words);
    } else if (comm == "parse"){	
        std::string source;
        std::cin >> source;
        words.ParseText2Set(source);
    } else if (comm == "repeat"){
        words.RepeatWords();
    } else if (comm == "show"){
        words.PrintUnknownWords();
    } else if (comm == "help"){
        HelpInfo();
        return;
    } else
        return;
}


std::string ParseCommand (std::string& comm){
    if(comm == "ADD" || comm == "add" || comm == "Add"){
       return "add";
    } else if(comm == "Parse" || comm == "PARSE" || comm == "parse"){
        return "parse";
    } else if(comm == "Show" || comm == "show" || comm == "SHOW"){
        return "show";
    } else if(comm == "DELETE" || comm == "delete" || comm == "Delete"){
        return "delete";
    } else if(comm == "repeat" || comm == "Repeat" || comm == "REPEAT"){
        return "repeat";
    } else if(comm == "HELP" || comm == "help" || comm == "Help"){
        return "help";
    } else if(comm == "exit" || comm == "Exit" || comm == "EXIT"){
        return "exit";
    } else throw std::logic_error("Unknown command.");
}


int main() {
    #ifdef DEBUG 
        EnglishWords words; 
        int count = 0;
        std::cout << words.dict.find("game")->second << std::endl;
    #endif

    #ifndef DEBUG
    try {
        EnglishWords words {};
        ProgramInfo();
        HelpInfo();
        std::string comm; 
        std::cout << "Command: "; std::cin >> comm;
        comm = ParseCommand(comm);
        while (comm != "exit"){
            ExecuteCommand(words, comm);
            std::cout << std::endl;
            std::cout << "Command: "; std::cin >> comm;
            comm = ParseCommand(comm);
        }
    }
    catch (std::logic_error& ex) {
        std::cout << ex.what() << " Please, try again." << std::endl;
    }
    #endif
    return 0;
}
