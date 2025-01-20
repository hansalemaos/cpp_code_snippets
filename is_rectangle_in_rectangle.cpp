#include <array>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

bool constexpr is_rect_in_rect(const std::array<int64_t, 4> &rect1, const std::array<int64_t, 4> &rect2)
{

    return (rect1[0] >= rect2[0] && rect1[1] >= rect2[1] && rect1[2] <= rect2[2] && rect1[3] <= rect2[3]);
}
int main()
{
    std::cout << is_rect_in_rect({1, 2, 3, 4}, {1, 2, 3, 4}) << std::endl;
    std::cout << is_rect_in_rect({1, 2, 3, 4}, {1, 2, 30, 40}) << std::endl;
    std::cout << is_rect_in_rect({0, 0, 300, 400}, {1, 2, 30, 40}) << std::endl;
    return 0;
}
