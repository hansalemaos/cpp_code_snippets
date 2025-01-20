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

constexpr bool is_lowercase_true(const std::string_view &s)
{
    if (s.size() != 4)
    {
        return false;
    }
    return (s[0] == 't' && s[1] == 'r' && s[2] == 'u' && s[3] == 'e');
}
int main()
{
    std::string teststring1{"test"};
    std::string teststring2{"true"};
    std::string teststring3{"false"};
    std::cout << is_lowercase_true(teststring1) << std::endl;
    std::cout << is_lowercase_true(teststring2) << std::endl;
    std::cout << is_lowercase_true(teststring3) << std::endl;
    return 0;
}
