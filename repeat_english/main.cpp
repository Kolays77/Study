#include <iostream>
#include <utility>
#include <string>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>

void ToLower(std::string& word){
    for (auto& letter : word) {
        if (letter >= 'A' && letter <= 'Z') { 
            letter = tolower(letter);
        }
    }  
}


bool IsServiceSymbol(char& ch){
    return !((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 121));
}


void ClearWord(std::string& word){
    // ---word -> word
    while(IsServiceSymbol(*(word.end() - 1)) && !word.empty()){
        word.pop_back();
    }

    // word,!=- -> word
    while(IsServiceSymbol(*(word.begin())) && !word.empty()){
        word.erase(word.begin());
    }

    // Tom's -> Tom, you'd -> you, Can't -> Can, I'm  -> I
    if(*(word.end() - 2) == '\''){ // word = ....'.
        word.erase(word.end()-2, word.end()-1);
    }

    // we've -> we, i'll -> i, you're -> you
    if(*(word.end() - 3) == '\'' ){ // word = ....'..
        word.erase(word.end()-3, word.end());
    }
}

void Print(std::ofstream& out, const std::unordered_set<std::string>& set){
    for(const auto& item: set){
        out << item << std::endl;
    }
}

void Print(std::ofstream& out, const std::unordered_map<std::string, int>& map){
    for(const auto& item: map){
        out << item.first << " " << item.second << std::endl;
    }
}


class EnglishWords{
private:
    std::string source_known {};
    std::string source_unknown {};
    std::string source_dict {};
    std::unordered_set<std::string> known_words;
    std::unordered_map<std::string, int> unknown_words;
public:
    std::map<std::string, std::string> dict;

public:
    explicit EnglishWords(std::string source1 = "default_known_words.txt",
                          std::string source2 = "default_unknown_words.txt",
                          std::string source3 = "default_dict_with_def.txt") :
                            source_known(std::move(source1)),
                            source_unknown(std::move(source2)),
                            source_dict(std::move(source3)) {
                        UploadKnownFromFile();
                        UploadUnknownFromFile();
                        UploadDictFromFile();
    }

    ~EnglishWords() {
        LoadWordsToFile();
    }


    void UploadDictFromFile() {
        std::ifstream fin(source_dict);
        if (!fin.is_open())
            if(source_dict == "default_dict_with_def.txt"){
                std::fstream file(source_dict);
                file.close();
                return;
            } else{
                throw std::logic_error("UploadDictFromFile: File can't be opened");
            }
                
        else {
            std::string word, part_def1, part_def2 ;
            while (fin >> word >> part_def1) {                
                getline(fin, part_def2);
                ToLower(word);
                dict[word] = part_def1 + part_def2;
            }
        }
    }
    


    size_t GetKnownWordsSize() {
        return known_words.size();
    }


    size_t GetUnknownWordsSize() {
        return unknown_words.size();
    }


    void LoadWordsToFile() {
        std::ofstream out_known(source_known);
        std::ofstream out_unknown(source_unknown);
        Print(out_known, known_words);
        Print(out_unknown, unknown_words);
        out_known.close();
        out_unknown.close();
    }

    void UploadUnknownFromFile() {
        std::fstream fin(source_unknown);
        if (!fin.is_open())
            if(source_unknown == "default_unknown_words.txt"){
                std::ofstream out(source_unknown);
                out.close();
                return;
            } else
                throw std::logic_error("UploadDictFromFile: File can't be opened");
        else{
            std::string word;
            int state;
            while(fin >> word >> state)
                unknown_words[std::move(word)] = state;
        }
    }


    void UploadKnownFromFile() {
        std::fstream fin(source_known);
        if (!fin.is_open())
            if (source_known == "default_known_words.txt") {
                std::ofstream out(source_known);
                out.close();
                return;
            } else
                throw std::logic_error("UploadDictFromFile: File can't be opened");
        else{
            std::string word;
            while(fin >> word) 
                known_words.insert(word);
        }
    }

    void AddWord(std::string& word) {
        ToLower(word);
        unknown_words[word] = 0;
    }

    void ShowKnownWords() {
        for(const auto& word: known_words){
            std::cout << word << std::endl;
        }
    }

    void ShowUnknownWords() {
        for(const auto& word: unknown_words){
            std::cout << word.first << std::endl;
        }
    }
	 
    void ParseText2Set(const std::string& source) {
        std::ifstream fin;
        fin.open(source);
        if (!fin.is_open())
            throw std::logic_error("File to parse can't be opened");
        else{
            std::string word;
            while(fin >> word){
                ClearWord(word);
                ToLower(word);
                if(known_words.find(word) != known_words.end()){
                    continue;
                } else{
                    if(unknown_words.at(word)){
                        continue;
                    } else{
                        unknown_words[word] = 0;
                    }
                }
            }
        }
        fin.close();
    }

    void UpdateUnknown() {
        std::unordered_map<std::string, int> temp;
        for(auto& it: unknown_words){
            if(it.second <= 1){
                temp[it.first] = it.second;
            }
        }
        unknown_words.clear();
        unknown_words = std::move(temp);
    }

    void RepeatWords() {
        std::string comm;
        for (auto& word: unknown_words){
            std::cout << "Do you know word : " <<  word.first << std::endl;
            std::cin >> comm;
            if(comm == "stop" || comm == "STOP" || comm == "Stop") {
                break;
            }
            if (comm == "n"){
                std::string find_word = word.first;

                for (auto & c: find_word) c = toupper(c); //word in dict : WORD "...def..."
                auto def = dict.find(find_word);
                if (def == dict.end()){
                    std::cout <<"No definition."  << std::endl;
                } else{
                    std::cout <<"Definition : " << def->second << std::endl;
                }
            } else {
                word.second++;
                if(word.second > 2){
                    known_words.insert(word.first);
                }
            }
        }
        UpdateUnknown();
    }
};


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


void AddWords(EnglishWords& words) {
    std::cout << "You can type 'Stop', if you gonna stop adding words" << std::endl;
    std::string word;
    std::unordered_set<std::string> set;
    while (std::cin >> word){
        if (word == "stop" || word == "STOP" || word == "Stop"){
            std::cout << "You wanna stop adding? Yes(y)/No(n)" << std::endl;
            std::cin >> word;
            if(word == "y" || word == "Y"){
                return;
            } else {
                continue;
            }
        }
        words.AddWord(word);
    }
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
        words.ShowUnknownWords();
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


int main (){
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
    system("pause"); 
    return 0;
}
