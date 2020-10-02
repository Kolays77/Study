#include "english_words.h"

void ToLower(std::string& word) {
    for (auto& letter : word)
        if (letter >= 'A' && letter <= 'Z') 
            letter = tolower(letter);     
}


bool IsServiceSymbol(char& ch) {
    return !((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 121));
}


void ClearWord(std::string& word){
    // ---word -> word
    while (IsServiceSymbol(*(word.end() - 1)) && !word.empty()) {
        word.pop_back();
    }

    // word,!=- -> word
    while (IsServiceSymbol(*(word.begin())) && !word.empty()) {
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

void Print(std::ofstream& out, const std::unordered_set<std::string>& set) {
    for(const auto& item: set){
        out << item << std::endl;
    }
}

void Print(std::ofstream& out, const std::unordered_map<std::string, int>& map) {
    for(const auto& item: map){
        out << item.first << " " << item.second << std::endl;
    }
}


EnglishWords::EnglishWords(std::string source1,
                           std::string source2,
                           std::string source3) :
                            source_known(std::move(source1)),
                            source_unknown(std::move(source2)),
                            source_dict(std::move(source3)) {
                        UploadKnownFromFile();
                        UploadUnknownFromFile();
                        UploadDictFromFile();
}

EnglishWords::~EnglishWords() {
    LoadWordsToFile();
}


void EnglishWords::UploadDictFromFile() {
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
        std::string word, def;
        while (fin >> word) {                
            getline(fin, def);
            dict[word] = def;
        }
    }
}

void EnglishWords::PrintStatistics() {
    std::cout << "size of known words " << this->known_words.size() << std::endl;
    std::cout << "size of unknown words " << this->unknown_words.size() << std::endl;
}


void EnglishWords::LoadWordsToFile() {
    std::ofstream out_known(source_known);
    std::ofstream out_unknown(source_unknown);
    Print(out_known, known_words);
    Print(out_unknown, unknown_words);
    out_known.close();
    out_unknown.close();
}

void EnglishWords::UploadUnknownFromFile() {
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

void EnglishWords::UploadKnownFromFile() {
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

void EnglishWords::AddWord(std::string& word) {
    ToLower(word);
    unknown_words[word] = 0;
}

void EnglishWords::PrintKnownWords() {
    for(const auto& word: known_words){
        std::cout << word << std::endl;
    }
}

void EnglishWords::PrintUnknownWords() {
    int count = 1;
    for(const auto& word: unknown_words){
        std::cout << count << ". " << word.first << std::endl;
        ++count;
    }
}
    
void EnglishWords::ParseText2Set(const std::string& source) {
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

void EnglishWords::UpdateUnknown() {
    std::unordered_map<std::string, int> temp;
    for(auto& it: unknown_words){
        if(it.second <= 1){
            temp[it.first] = it.second;
        }
    }
    unknown_words.clear();
    unknown_words = std::move(temp);
}

void EnglishWords::RepeatWords() {
    std::string comm;
    if (unknown_words.size() == 0) {
        std::cout << "Excellent job. You've repeat all words" << std::endl;
    }
    for (auto& word: unknown_words){
        std::cout << "Do you know word : " <<  word.first << std::endl;
        std::cin >> comm;
        if(comm == "stop" || comm == "STOP" || comm == "Stop")
            break;
        if (comm == "n"){
            std::string find_word = word.first;
                      
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