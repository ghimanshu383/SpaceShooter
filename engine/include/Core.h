//
// Created by ghima on 14-07-2024.
//
#include <cstdio>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

#ifndef LIGHTYEARS_CORE_H
#define LIGHTYEARS_CORE_H

namespace ly {
#define Log(M, ...) printf(M "\n", ##__VA_ARGS__)
    template<typename T>
    using List = std::vector<T>;
    template<typename T>
    using shared = std::shared_ptr<T>;
    template<typename T>
    using unique = std::unique_ptr<T>;
    template<typename T>
    using weak = std::weak_ptr<T>;
    template<typename T, typename R, typename S = std::less<T>>
    using Map = std::map<T, R, S>;
    template<typename T, typename R, typename S = std::hash<T>>
    using Dict = std::unordered_map<T, R, S>;
    template<typename T>
    using Set = std::unordered_set<T>;

    using uint8 = unsigned char;
}

#endif //LIGHTYEARS_CORE_H
