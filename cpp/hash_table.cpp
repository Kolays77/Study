#include <vector>
#include <string>
#include <iostream>
#include <algorithm> //для copy
#include <exception>
#include <type_traits>
#include <profile.h>
#include "profile.h"


template <typename K, typename V>
struct HashData{
    K* key = new K;
    V* value = new V;
    HashData() : key(nullptr), value(nullptr){};
    HashData(const K& k, const V& v){
        *key = k;
        *value = v;
    };
    //HashData(const HashData& data) : key(data.key), value(data.value){};
};

namespace std {
    std::string to_string(const char *x) { return std::string(x); }
    std::string to_string(const std::string &x) { return x; }
}


template <typename K, typename V>
class HashTable{
private:
    size_t size;
    std::vector<HashData<K,V>> data;
public:
    explicit HashTable(size_t n) : size(n), data(std::vector<HashData<K,V>>(n)){};


    [[nodiscard]] size_t hash(const K& key) const{
        std::string str(std::to_string(key));
        size_t ans = 0;
        for(char c: str)  {
            ans += c;
        }
        return ans % this->size;
    }


    [[nodiscard]] size_t getSize() const{
        return size;
    }

    [[nodiscard]] size_t getPosition(const K& key) const{
        size_t start_key = hash(key);
        bool stop = false;
        bool found = false;
        size_t position = start_key;
        while(data[position].key != -1 && !found && !stop){
            if(data[position].key == hash(key)){
                found = true;
            }else{
                position = hash(position+1);
                if(position == start_key){
                    stop = true;
                }
            }
        }
        return position;
    }

    HashData<K,V> getValue(const K& k){
        return data[getPosition(k)];
    }

    void erase(size_t index){
        size_t start_key = hash(index);
        bool stop = false;
        bool found = false;
        size_t position = start_key;
        while(data[position].key != -1 && !found && !stop){
            if(data[position].key == index){
                found = true;
                data[position].key = -1;
                data[position].data = -1;
            }else{
                position = hash(position+1);
                if(position == start_key){
                    stop = true;
                }
            }
        }
    }

    void put(const HashData<K,V>& item) {
        size_t hash_key = hash(item.key);
        if (data[hash_key].key == -1) {
            data[hash_key].key = item.key;
            data[hash_key].value = item.value;
        } else {
            if (data[hash_key].key == item.key) {
                data[hash_key].value = item.value;
            } else {
                size_t next_key = hash(hash_key + 1);
                while (data[next_key].key != -1 && data[next_key].key != item.key) {
                    next_key = hash(next_key + 1);
                }
                if (data[next_key].key == -1) {
                    data[next_key].key = item.key;
                    data[next_key].value = item.value;
                } else {
                    data[next_key].value = item.value;
                }
            }
        }
    }
};


template <typename K, typename V>
std::ostream& operator<<(std::ostream& out, const HashData<K,V>& data){
    if(data.key == -1){
        return  out << "NULL" << " : " << "NULL";
    }
    return  out << data.key << " : " << data.value;
}

/*
template <typename K, typename V>
std::ostream& operator<<(std::ostream& out, const HashTable<K,V>& table){
    for(size_t i = 0; i < table.getSize(); i++) {
        out << table[i] << std::endl;
    }
    return out;
}
*/
int main(){
    HashTable<double,int> table(100000);
    auto str = "a";
    std::cout << table.hash(str);
    return 0;
}