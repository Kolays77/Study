#pragma once
#include <vector>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <unordered_set>

#include <unordered_map>
/*
 * [ ... ] - vector and list
 * ( , ) - pair
 * { ... } - map
 *
 */
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1,T2>& item){
    return out <<"("<< item.first << " , " << item.second << ")";
}

template<typename Iterator>
std::ostream& PrintRange(std::ostream& os, Iterator begin, Iterator end) {
    for (auto it = begin; it != end; os << *it++)
        if (it != begin) os << ", ";
    return os;
}


// вывод map :
template<class K, class V>
std::ostream& operator<<(std::ostream& os, const std::map<K,V>& map) {
    os << "{";
    return PrintRange(os, map.begin(), map.end()) << "}";

}

// вывод list :
template<class T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& lst) {
    return os << "[" << PrintRange(os, lst.begin(), lst.end()) << "]";

}


// вывод vector:
template<class X>
std::ostream& operator<<(std::ostream& os, const std::vector<X>& vec) {
    os << "[";
    return PrintRange(os, vec.begin(), vec.end()) << "]";

}


// вывод set
template<class X>
std::ostream& operator<<(std::ostream& os, const std::set<X>& set) {
    os << "(";
    return PrintRange(os, set.begin(), set.end()) << ")";
}

// вывод set
template<class X>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<X>& set) {
    os << "(";
    return PrintRange(os, set.begin(), set.end()) << ")";
}

// вывод set
template<class K, class V>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<K,V>& m) {
    os << "{";
    return PrintRange(os, m.begin(), m.end()) << "}";
}