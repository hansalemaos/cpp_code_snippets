#include <algorithm>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

constexpr static bool is_digit(char c)
{
    return c <= '9' && c >= '0';
}

constexpr static int64_t satoll_impl(const char *str, int64_t value = 0)
{
    return *str ? is_digit(*str) ? satoll_impl(str + 1, (*str - '0') + value * 10) : 0 : value;
}

int64_t static constexpr mystoi(const std::string &str)
{
    return satoll_impl(str.c_str());
}

int main()
{
    std::string mystring{"213234"};
    int64_t value{mystoi(mystring)};
    std::cout << value << std::endl;

    return 0;
}
