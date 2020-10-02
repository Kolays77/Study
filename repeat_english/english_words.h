#pragma once

#include <iostream>
#include <utility>
#include <string>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>

void ToLower(std::string& word);
bool IsServiceSymbol(char& ch);
void ClearWord(std::string& word);

void Print(std::ofstream& out, const std::unordered_set<std::string>& set);
void Print(std::ofstream& out, const std::unordered_map<std::string, int>& map);


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
                          std::string source3 = "default_dict_with_def.txt");

    ~EnglishWords();
    void UploadDictFromFile();
    void PrintStatistics();
    void LoadWordsToFile();    
    void UploadUnknownFromFile();
    void UploadKnownFromFile();
    void AddWord(std::string& word);
    void PrintKnownWords();
    void PrintUnknownWords();
    void ParseText2Set(const std::string& source);
    void UpdateUnknown();
    void RepeatWords();
};

void AddWords(EnglishWords& words);