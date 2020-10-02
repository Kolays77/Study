#include "tasks.h"

Tasks::Tasks(const std::string& s) : _source(s){
    LoadFromFile(s);
}

void Tasks::LoadFromFile(const std::string& source) {
    std::ifstream in(source);
    // if not exist input source file, create 
    size_t count_sections = 0;
    in >> count_sections;
    for (size_t i = 0; i < count_sections; ++i) {
        std::string section;
        size_t count_tasks = 0;
        in >> section >> count_tasks;
        data[section] = std::vector<std::string>(count_tasks);
        for (size_t j = 0; j < count_tasks; ++j) {
            std::getline(in, data[section][j]);
        }
    }  
}

Tasks::~Tasks() {
    std::ofstream out(_source);
    out << data.size() << std::endl;
    for (auto& sec : data) {
        out << sec.first << std::endl;
        out << sec.second.size() << std::endl;
        for (auto& task: sec.second) {
            out << task << std::endl;
        }
    }
    out.close();
}

// Delete empty sections
void Tasks::Update() { 
    std::map<std::string, std::vector<std::string>> temp;
    for (auto& it : data) {
        if (it.second.size()) {
            temp[it.first] = it.second;
        }
    }
    data = temp;
}

void Tasks::Print() const {
    for (auto& it : data) {
        std::cout << it.first << " : " << std::endl;
        for (auto& tasks: it.second) {
            std::cout << '\t' << tasks << std::endl;
        }
    }
}

void Tasks::Delete(std::string section) {
    data.erase(section);
}

void Tasks::Delete(std::string section, std::string task) {
    auto begin = data[section].begin();
    auto end = data[section].end();
    auto it = std::find(begin, end, task);
    if (it != end) {
        data[section].erase(it);
    }
}

void Tasks::Add(std::string section, std::string task) {
    data[section].push_back(task);
    // if not ... exception
}
