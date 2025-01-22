#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename T>
static void constexpr _get_rectangle_coordinates_surface(std::vector<std::pair<T, T>> &positions, int64_t x, int64_t y,
                                                         int64_t width, int64_t height)
{

    for (int64_t i{}; i < (width + 1); i++)
    {
        positions.emplace_back(std::make_pair(x + i, y));
        positions.emplace_back(std::make_pair(x + i, y + height));
    };
    for (int64_t j{}; j < (height + 1); j++)
    {
        positions.emplace_back(std::make_pair(x, y + j));
        positions.emplace_back(std::make_pair(x + width, y + j));
    }
}
template <typename T> std::vector<std::pair<T, T>> get_rectangle_coordinates_surface(T x, T y, T width, T height)
{
    std::vector<std::pair<T, T>> positions;
    positions.reserve((width + 2) * (height + 2) * 2);
    _get_rectangle_coordinates_surface(positions, x, y, width, height);
    return positions;
}
int main()
{
    std::vector<std::pair<int, int>> vectest0{get_rectangle_coordinates_surface(0, 0, 10, 20)};
    for (int i = 0; i < vectest0.size(); i++)
    {
        std::cout << vectest0[i].first << " " << vectest0[i].second << std::endl;
    }

    return 0;
}
