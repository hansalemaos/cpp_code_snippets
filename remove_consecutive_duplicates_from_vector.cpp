#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

template <typename T, typename U> void remove_consecutive_duplicates(std::vector<std::pair<T, U>> &v)
{
    v.erase(std::unique(v.begin(), v.end(),
                        [](const auto &a, const auto &b) { return a.first == b.first && a.second == b.second; }),
            v.end());
}
template <typename T> void remove_consecutive_duplicates(std::vector<T> &v)
{
    v.erase(std::unique(v.begin(), v.end(), [](const auto &a, const auto &b) { return a == b; }), v.end());
}
int main()
{
    std::vector<std::pair<int, int>> vectest{
        std::make_pair(1, 2), std::make_pair(1, 3), std::make_pair(1, 3), std::make_pair(1, 3), std::make_pair(1, 4),
    };

    remove_consecutive_duplicates(vectest);
    for (const auto &p : vectest)
    {
        std::cout << p.first << " " << p.second << std::endl;
    }

    std::vector<int> vectest2{1, 2, 3, 4, 5, 56, 6, 6, 6, 6, 6, 6, 7, 7, 7};

    remove_consecutive_duplicates(vectest2);
    for (const auto &p : vectest2)
    {
        std::cout << p << std::endl;
    }
    return 0;
}
