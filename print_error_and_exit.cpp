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

static constexpr std::string_view IRed{"\033[0;91m"};   // Red
static constexpr std::string_view Color_Off{"\033[0m"}; // Text Reset

void print_error_and_exit(const std::string &msg, int exit_code)
{
    std::cerr << IRed << msg << Color_Off << '\n';
    exit(exit_code);
}
int main()
{

    print_error_and_exit("something wrong", 1);

    return 0;
}
