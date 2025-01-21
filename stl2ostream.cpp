#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <any>
#include <array>
#include <cctype>
#include <cmath>
#include <compare>
#include <cstring>
#include <deque>
#include <filesystem>
#include <forward_list>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <string_view>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>
template <typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    if (v.size() == 0)
    {
        os << "[]";
        return os;
    }
    auto it{v.begin()};

    os << '[';
    size_t vcounter{0};
    while (it != v.end())
    {
        vcounter++;
        os << *it;
        if (v.size() > 1)
        {
            os << ", ";
        }

        if (vcounter == v.size() - 1)
        {
            break;
        }
        it++;
    }
    if (v.size() > 1)
    {
        it++;
        os << *it;
    }
    os << ']';

    return os;
}

template <typename T, typename U> std::ostream &operator<<(std::ostream &os, const std::vector<std::pair<T, U>> &v)

{
    if (v.size() == 0)
    {
        os << "[]";
        return os;
    }
    auto it{v.begin()};

    os << '[';
    size_t vcounter{0};
    while (it != v.end())
    {
        vcounter++;
        os << '(';
        os << it->first;
        os << ", ";
        os << it->second;
        os << ')';
        if (v.size() > 1)
        {
            os << ", ";
        }
        if (vcounter == v.size() - 1)
        {
            break;
        }
        it++;
    }
    if (v.size() > 1)
    {
        it++;
        os << '(';
        os << it->first;
        os << ", ";
        os << it->second;
        os << ")";
    }
    os << ']';

    return os;
}

template <typename T> std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v)

{
    if (v.size() == 0)
    {
        os << "[]";
        return os;
    }
    auto it{v.begin()};

    os << '[';
    size_t vcounter{0};
    while (it != v.end())
    {
        vcounter++;
        os << *it;
        if (v.size() > 1)
        {
            os << ", ";
        }

        if (vcounter == v.size() - 1)
        {
            break;
        }
        it++;
    }
    if (v.size() > 1)
    {
        it++;
        os << *it;
    }
    os << ']';

    return os;
}

template <typename T> std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<std::vector<T>>> &v)

{
    if (v.size() == 0)
    {
        os << "[]";
        return os;
    }
    auto it{v.begin()};

    os << '[';
    size_t vcounter{0};
    while (it != v.end())
    {
        vcounter++;
        os << *it;
        if (v.size() > 1)
        {
            os << ',';
        }

        if (vcounter >= v.size() - 1)
        {
            break;
        }
        it++;
    }
    if (v.size() > 1)
    {
        it++;
        os << *it;
    }
    os << ']';

    return os;
}

template <typename T, size_t N> std::ostream &operator<<(std::ostream &os, const std::array<T, N> &v)
{
    std::vector<T> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}

template <typename T, typename U> std::ostream &operator<<(std::ostream &os, const std::map<T, U> &v)
{
    std::vector<std::pair<T, U>> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}
template <typename T, typename U> std::ostream &operator<<(std::ostream &os, const std::multimap<T, U> &v)
{
    std::vector<std::pair<T, U>> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}
template <typename T, typename U> std::ostream &operator<<(std::ostream &os, const std::unordered_map<T, U> &v)
{
    std::vector<std::pair<T, U>> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}
template <typename T, typename U> std::ostream &operator<<(std::ostream &os, const std::unordered_multimap<T, U> &v)
{
    std::vector<std::pair<T, U>> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}

template <typename T> std::ostream &operator<<(std::ostream &os, const std::set<T> &v)
{
    std::vector<T> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}
template <typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &v)
{
    std::vector<T> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}
template <typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_multiset<T> &v)
{
    std::vector<T> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}
template <typename T> std::ostream &operator<<(std::ostream &os, const std::list<T> &v)
{
    std::vector<T> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}
template <typename T> std::ostream &operator<<(std::ostream &os, const std::queue<T> &v)
{
    std::vector<T> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}
template <typename T> std::ostream &operator<<(std::ostream &os, const std::priority_queue<T> &v)
{
    std::vector<T> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}
template <typename T> std::ostream &operator<<(std::ostream &os, const std::forward_list<T> &v)
{
    std::vector<T> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}
template <typename T> std::ostream &operator<<(std::ostream &os, const std::deque<T> &v)
{
    std::vector<T> tmpv{v.begin(), v.end()};
    os << tmpv;
    return os;
}
int main()
{

    std::vector<int> vec1{1, 2, 3, 34, 45, 5, 6, 76, 78};
    std::vector<float> vec2{1.4, 2, 3.33, 3.4, 4.5, 5, 6, 76, 78};
    std::vector<std::pair<std::string, float>> vec3{{"a", 1.4}, {"b", 2}, {"c", 3.33}};
    std::vector<std::vector<std::pair<std::string, float>>> vec4{{{"a", 1.4}, {"b", 2}, {"c", 3.33}},
                                                                 {{"a", 1.4}, {"b", 2}, {"c", 3.33}}};
    std::vector<std::vector<std::vector<std::pair<std::string, float>>>> vec5{
        {{{"a", 1.4}, {"b", 2}, {"c", 3.33}}, {{"a", 1.4}, {"b", 2}, {"c", 3.33}}},
        {{{"a", 1.4}, {"b", 2}, {"c", 3.33}}, {{"a", 1.4}, {"b", 2}, {"c", 3.33}}}

    };
    std::vector<std::vector<std::vector<std::vector<std::pair<std::string, float>>>>> vec6{
        {{{{"a", 1.4}, {"b", 2}, {"c", 3.33}}, {{"a", 1.4}, {"b", 2}, {"c", 3.33}}},
         {{{"a", 1.4}, {"b", 2}, {"c", 3.33}}, {{"a", 1.4}, {"b", 2}, {"c", 3.33}}}

        }};
    std::array<int, 9> arra1{1, 2, 3, 34, 45, 5, 6, 76, 78};
    std::map<std::string, float> map1{{"a", 1.4}, {"b", 2}, {"c", 3.33}};
    std::map<std::string, std::vector<float>> map2{{"a", {1.4}}, {"b", {2, 3.4}}, {"c", {3.33, 7.54, 1.2}}};
    std::unordered_map<std::string, float> umap1{{"a", 1.4}, {"b", 2}, {"c", 3.33}};
    std::unordered_map<std::string, std::vector<float>> umap2{{"a", {1.4}}, {"b", {2, 3.4}}, {"c", {3.33, 7.54, 1.2}}};

    std::unordered_multimap<std::string, float> ummap1{{"a", 1.4}, {"b", 2}, {"c", 3.33}};
    std::unordered_multimap<std::string, std::vector<float>> ummap2{
        {"a", {1.4}}, {"b", {2, 3.4}}, {"c", {3.33, 7.54, 1.2}}};
    std::multimap<std::string, float> mmap1{{"a", 1.4}, {"b", 2}, {"c", 3.33}};
    std::multimap<std::string, std::vector<float>> mmap2{{"a", {1.4}}, {"b", {2, 3.4}}, {"c", {3.33, 7.54, 1.2}}};
    std::cout << vec1 << std::endl;
    std::cout << vec2 << std::endl;
    std::cout << vec3 << std::endl;
    std::cout << vec4 << std::endl;

    std::cout << vec5 << std::endl;
    std::cout << vec6 << std::endl;
    std::cout << arra1 << std::endl;
    std::cout << map1 << std::endl;
    std::cout << map2 << std::endl;
    std::cout << umap1 << std::endl;
    std::cout << umap2 << std::endl;
    std::cout << ummap1 << std::endl;
    std::cout << ummap2 << std::endl;
    std::cout << mmap1 << std::endl;
    std::cout << mmap2 << std::endl;
    std::set<int> set1{1, 2, 3, 34, 45, 5, 6, 76, 78};
    std::set<float> set2{1.4, 2, 3.33, 3.4, 4.5, 5, 6, 76, 78};
    std::set<std::pair<std::string, float>> set3{{"a", 1.4}, {"b", 2}, {"c", 3.33}};

    std::cout << set1 << std::endl;
    std::cout << set2 << std::endl;
    std::cout << set3 << std::endl;

    std::unordered_set<int> unordered_set1{1, 2, 3, 34, 45, 5, 6, 76, 78};
    std::unordered_set<float> unordered_set2{1.4, 2, 3.33, 3.4, 4.5, 5, 6, 76, 78};

    std::cout << unordered_set1 << std::endl;
    std::cout << unordered_set2 << std::endl;

    std::unordered_multiset<int> unordered_multiset1{1, 2, 3, 34, 45, 5, 6, 76, 78};
    std::unordered_multiset<float> unordered_multiset2{1.4, 2, 3.33, 3.4, 4.5, 5, 6, 76, 78};
    std::cout << unordered_multiset1 << std::endl;
    std::cout << unordered_multiset2 << std::endl;

    std::list<int> list1{1, 2, 3, 34, 45, 5, 6, 76, 78};
    std::list<float> list2{1.4, 2, 3.33, 3.4, 4.5, 5, 6, 76, 78};
    std::list<std::pair<std::string, float>> list3{{"a", 1.4}, {"b", 2}, {"c", 3.33}};
    std::cout << list1 << std::endl;
    std::cout << list2 << std::endl;
    std::cout << list3 << std::endl;

    std::deque<int> deque1{1, 2, 3, 34, 45, 5, 6, 76, 78};
    std::deque<float> deque2{1.4, 2, 3.33, 3.4, 4.5, 5, 6, 76, 78};
    std::deque<std::pair<std::string, float>> deque3{{"a", 1.4}, {"b", 2}, {"c", 3.33}};
    std::cout << deque1 << std::endl;
    std::cout << deque2 << std::endl;
    std::cout << deque3 << std::endl;

    return 0;
}
