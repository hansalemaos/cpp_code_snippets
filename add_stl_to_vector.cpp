#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename T> auto add_container_to_vec(const T &v1, const T &v2)
{
    T resultvec;
    resultvec.reserve(v1.size() + v2.size());
    auto it1 = v1.begin(), it2 = v2.begin();
    while (it1 != v1.end())
    {
        resultvec.emplace_back(*it1);
        ++it1;
    }
    while (it2 != v2.end())
    {
        resultvec.emplace_back(*it2);
        ++it2;
    }
    return resultvec;
}
template <typename T> void add_container_to_vec_inplace(T &resultvec, const T &v2)
{

    auto it2 = v2.begin();
    while (it2 != v2.end())
    {
        resultvec.emplace_back(*it2);
        ++it2;
    }
}
int main()
{
    std::vector<std::vector<int>> vectest0{{1, 2}, {1, 3}, {1, 3}, {1, 3}, {1, 4},
                                           {1, 2}, {1, 3}, {1, 3}, {1, 3}, {1, 4}};
    std::vector<std::vector<int>> vectest1{{1, 2}, {1, 3}, {1, 3}, {1, 3}, {1, 4},
                                           {1, 2}, {1, 3}, {1, 3}, {1, 3}, {1, 4}};
    auto vectorofvectors{add_container_to_vec(vectest0, vectest1)};
    for (auto &i : vectorofvectors)
    {
        for (auto &j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    add_container_to_vec_inplace(vectorofvectors, vectest1);
    for (auto &i : vectorofvectors)
    {
        for (auto &j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
