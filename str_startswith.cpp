#include <array>
#include <cmath>
#include <cstdint>
#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

constexpr bool str_startswith(const std::string_view haystack, const std::string_view needle)
{
    if (!haystack.size() || !needle.size())
    {
        return false;
    }
    if (haystack.size() < needle.size())
    {
        return false;
    }
    for (size_t i = 0; i < needle.size(); i++)
    {
        if (haystack[i] != needle[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{

    std::string test1{" x x   hello  x "};
    std::cout << str_startswith(test1, " x") << std::endl;
    std::cout << str_startswith(test1, "x x") << std::endl;

    return 0;
}
