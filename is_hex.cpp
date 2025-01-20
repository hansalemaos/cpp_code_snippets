#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

static constexpr std::string_view hex_upper_letters_string_view = "0123456789ABCDEF";
static constexpr std::string_view hex_lower_letters_string_view = "0123456789abcdef";
static constexpr std::string_view prefix_0b = "0b";
static constexpr std::string_view prefix_01 = "01";
static constexpr std::string_view prefix_0x = "0x";
static constexpr std::string_view number_0 = "0";
constexpr bool is_hex_notation_upper_with_0x(const std::string_view input)
{
    return input.compare(0, 2, prefix_0x) == 0 && input.size() > 2 &&
           (input.find_first_not_of(hex_upper_letters_string_view, 2) == std::string_view::npos);
}
constexpr bool is_hex_notation_upper_without_0x(const std::string_view input)
{
    return input.size() > 0 && (input.find_first_not_of(hex_upper_letters_string_view, 2) == std::string_view::npos);
}
constexpr bool is_hex_notation_lower_with_0x(const std::string_view input)
{
    return input.compare(0, 2, prefix_0x) == 0 && input.size() > 2 &&
           (input.find_first_not_of(hex_lower_letters_string_view, 2) == std::string_view::npos);
}
constexpr bool is_hex_notation_lower_without_0x(const std::string_view input)
{
    return input.size() > 0 && (input.find_first_not_of(hex_lower_letters_string_view, 2) == std::string_view::npos);
}
int main()
{

    std::string test1{"0x1234"};
    std::string test2{"0x12xx34"};
    std::string test3{"0x12hf234"};
    std::string test4{"0x1f234"};
    std::string test5{"1234"};
    std::string test6{"0X1234"};
    std::string test7{"0x1  234"};
    std::string test8{"0X1234"};
    std::cout << is_hex_notation_upper_with_0x(test1) << std::endl;
    std::cout << is_hex_notation_upper_with_0x(test2) << std::endl;
    std::cout << is_hex_notation_upper_with_0x(test3) << std::endl;
    std::cout << is_hex_notation_upper_with_0x(test4) << std::endl;
    std::cout << is_hex_notation_upper_with_0x(test5) << std::endl;
    std::cout << is_hex_notation_upper_with_0x(test6) << std::endl;
    std::cout << is_hex_notation_upper_with_0x(test7) << std::endl;
    std::cout << is_hex_notation_upper_with_0x(test8) << std::endl;

    std::cout << is_hex_notation_upper_without_0x(test1) << std::endl;
    std::cout << is_hex_notation_upper_without_0x(test2) << std::endl;
    std::cout << is_hex_notation_upper_without_0x(test3) << std::endl;
    std::cout << is_hex_notation_upper_without_0x(test4) << std::endl;
    std::cout << is_hex_notation_upper_without_0x(test5) << std::endl;
    std::cout << is_hex_notation_upper_without_0x(test6) << std::endl;
    std::cout << is_hex_notation_upper_without_0x(test7) << std::endl;
    std::cout << is_hex_notation_upper_without_0x(test8) << std::endl;

    std::cout << is_hex_notation_lower_with_0x(test1) << std::endl;
    std::cout << is_hex_notation_lower_with_0x(test2) << std::endl;
    std::cout << is_hex_notation_lower_with_0x(test3) << std::endl;
    std::cout << is_hex_notation_lower_with_0x(test4) << std::endl;
    std::cout << is_hex_notation_lower_with_0x(test5) << std::endl;
    std::cout << is_hex_notation_lower_with_0x(test6) << std::endl;
    std::cout << is_hex_notation_lower_with_0x(test7) << std::endl;
    std::cout << is_hex_notation_lower_with_0x(test8) << std::endl;

    std::cout << is_hex_notation_lower_without_0x(test1) << std::endl;
    std::cout << is_hex_notation_lower_without_0x(test2) << std::endl;
    std::cout << is_hex_notation_lower_without_0x(test3) << std::endl;
    std::cout << is_hex_notation_lower_without_0x(test4) << std::endl;
    std::cout << is_hex_notation_lower_without_0x(test5) << std::endl;
    std::cout << is_hex_notation_lower_without_0x(test6) << std::endl;
    std::cout << is_hex_notation_lower_without_0x(test7) << std::endl;
    std::cout << is_hex_notation_lower_without_0x(test8) << std::endl;

    return 0;
}
