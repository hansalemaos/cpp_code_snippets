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

constexpr int32_t get_platform()
{
#ifdef __ANDROID__
    return 0;
#elif _WIN32
    return 1;
#elif _WIN64
    return 1;
#elif __APPLE__ || __MACH__
    return 2;
#elif __linux__
    return 3;
#elif __FreeBSD__
    return 4;
#elif __unix || __unix__
    return 5;
#else
    return 6;
#endif
}
int main()
{

    std::cout << get_platform() << std::endl;

    return 0;
}
