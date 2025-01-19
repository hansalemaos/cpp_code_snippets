#include <array>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <tuple>
#include <vector>

template <typename T> static auto calculate_rectangle_data(const std::array<T, 4> &bounds_array)
{
    auto start_x = bounds_array[0];
    auto start_y = bounds_array[1];
    auto end_x = bounds_array[2];
    auto end_y = bounds_array[3];
    auto center_y = (start_y + end_y) / 2;
    auto area = (end_x - start_x) * (end_y - start_y);
    auto width = end_x - start_x;
    auto height = end_y - start_y;
    auto center_x = (start_x + end_x) / 2;
    bool is_square = (width == height);
    double w_h_relation = -1;
    if (height > 0)
    {
        w_h_relation = (double)width / (double)height;
    }
    return std::tuple<T, T, T, T, T, T, T, T, T, double, bool>{
        start_x, start_y, end_x, end_y, center_x, center_y, area, width, height, w_h_relation, is_square};
}

int main()
{

    auto [start_x, start_y, end_x, end_y, center_x, center_y, area, width, height, w_h_relation, is_square] =
        calculate_rectangle_data(std::array<int32_t, 4>{10, 20, 300, 400});
    std::cout << start_x << " " << start_y << " " << end_x << " " << end_y << " " << center_x << " " << center_y << " ";
    std::cout << area << " " << width << " " << height << " " << w_h_relation << " " << is_square << std::endl;
    return 0;
}
