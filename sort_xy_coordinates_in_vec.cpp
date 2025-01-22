#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename T> void constexpr sort_by_x(std::vector<std::pair<T, T>> &v, bool ascending = true)
{
    if (ascending)
    {
        std::sort(v.begin(), v.end(),
                  [](const std::pair<T, T> &a, const std::pair<T, T> &b) { return a.first < b.first; });
    }
    else
    {
        std::sort(v.begin(), v.end(),
                  [](const std::pair<T, T> &a, const std::pair<T, T> &b) { return a.first > b.first; });
    }
}

template <typename T> void constexpr sort_by_y(std::vector<std::pair<T, T>> &v, bool ascending = true)
{
    if (ascending)
    {
        std::sort(v.begin(), v.end(),
                  [](const std::pair<T, T> &a, const std::pair<T, T> &b) { return a.second < b.second; });
    }
    else
    {
        std::sort(v.begin(), v.end(),
                  [](const std::pair<T, T> &a, const std::pair<T, T> &b) { return a.second > b.second; });
    }
}

template <typename T>
void constexpr sort_by_xy(std::vector<std::pair<T, T>> &v, bool ascending_x = true, bool ascending_y = true)
{
    if (ascending_x && ascending_y)
    {
        std::sort(v.begin(), v.end(), [](const std::pair<T, T> &a, const std::pair<T, T> &b) {
            if (a.first == b.first)
            {
                return a.second < b.second;
            }
            else
            {
                return a.first < b.first;
            }
        });
    }
    else if (!ascending_x && !ascending_y)
    {
        std::sort(v.begin(), v.end(), [](const std::pair<T, T> &a, const std::pair<T, T> &b) {
            if (a.first == b.first)
            {
                return a.second > b.second;
            }
            else
            {
                return a.first > b.first;
            }
        });
    }
    else if (!ascending_x && ascending_y)
    {
        std::sort(v.begin(), v.end(), [](const std::pair<T, T> &a, const std::pair<T, T> &b) {
            if (a.first == b.first)
            {
                return a.second < b.second;
            }
            else
            {
                return a.first > b.first;
            }
        });
    }
    else if (ascending_x && !ascending_y)
    {
        std::sort(v.begin(), v.end(), [](const std::pair<T, T> &a, const std::pair<T, T> &b) {
            if (a.first == b.first)
            {
                return a.second > b.second;
            }
            else
            {
                return a.first < b.first;
            }
        });
    }
}
int main()
{
    std::vector<std::pair<int, int>> test_vector{{1, 1}, {8, 8}, {2, 2},    {4, 4},   {5, 5}, {6, 6},
                                                 {7, 7}, {9, 9}, {111, 11}, {10, 10}, {3, 3}};

    sort_by_x(test_vector);
    for (int i = 0; i < test_vector.size(); i++)
    {
        std::cout << test_vector[i].first << " " << test_vector[i].second << std::endl;
    }
    sort_by_x(test_vector, false);
    for (int i = 0; i < test_vector.size(); i++)
    {
        std::cout << test_vector[i].first << " " << test_vector[i].second << std::endl;
    }

    sort_by_y(test_vector);
    for (int i = 0; i < test_vector.size(); i++)
    {
        std::cout << test_vector[i].first << " " << test_vector[i].second << std::endl;
    }
    sort_by_xy(test_vector);
    for (int i = 0; i < test_vector.size(); i++)
    {
        std::cout << test_vector[i].first << " " << test_vector[i].second << std::endl;
    }
    sort_by_xy(test_vector, false, false);

    for (int i = 0; i < test_vector.size(); i++)
    {
        std::cout << test_vector[i].first << " " << test_vector[i].second << std::endl;
    }

    return 0;
}
