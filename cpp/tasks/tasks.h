#pragma once
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

struct Tasks {
    std::string _source;
    std::map<std::string, std::vector<std::string>> data;
    
    Tasks(const std::string& s);
    ~Tasks(); 
    
    void LoadFromFile(const std::string& source);
    void Update();
    void Print() const;
    void Delete(std::string section);
    void Delete(std::string section, std::string task);
    void Add(std::string section, std::string task);
};
