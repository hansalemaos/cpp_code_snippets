#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

static constexpr std::string_view bool1 = "True";
static constexpr std::string_view bool2 = "False";
static constexpr std::string_view bool3 = "true";
static constexpr std::string_view bool4 = "false";
static constexpr std::string_view bool5 = "0";
static constexpr std::string_view bool6 = "1";
static constexpr std::string_view bool7 = "TRUE";
static constexpr std::string_view bool8 = "FALSE";

constexpr bool convert_string_to_bool(const std::string_view s)
{

    if (s == bool1 || s == bool3 || s == bool6 || s == bool7)
    {
        return true;
    }
    return false;
}

constexpr bool convert_string_to_bool_with_throw(const std::string_view s)
{

    if (s == bool1 || s == bool3 || s == bool6 || s == bool7)
    {
        return true;
    }
    if (s == bool2 || s == bool4 || s == bool5 || s == bool8)
    {
        return false;
    }
    throw std::invalid_argument{"neither true nor false"};
}

int main()
{
    std::string s1 = "true";
    std::string s2 = "False";
    std::string s3 = "true";
    std::string s4 = "false";
    std::string s5 = "0";
    std::string s6 = "1";
    std::string s7 = "TRUE";
    std::string s8 = "FALSE";
    std::cout << convert_string_to_bool(s1) << std::endl;
    std::cout << convert_string_to_bool(s2) << std::endl;
    std::cout << convert_string_to_bool(s3) << std::endl;
    std::cout << convert_string_to_bool(s4) << std::endl;
    std::cout << convert_string_to_bool(s5) << std::endl;
    std::cout << convert_string_to_bool(s6) << std::endl;
    std::cout << convert_string_to_bool(s7) << std::endl;
    std::cout << convert_string_to_bool(s8) << std::endl;

    return 0;
}
