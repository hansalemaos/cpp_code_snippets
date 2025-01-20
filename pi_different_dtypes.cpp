#ifdef _WIN32
#include <windows.h>
#endif

#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>

template <typename T> constexpr T pi_const()
{
    return (T)(3.14159265358979323846);
}

int main()
{
    static constexpr int32_t pi1 = pi_const<int32_t>();
    static constexpr int64_t pi2 = pi_const<int64_t>();
    static constexpr float pi3 = pi_const<float>();
    static constexpr double_t pi4 = pi_const<double>();
    std::cout << pi1 << " " << pi2 << " " << pi3 << " " << pi4 << std::endl;

    return 0;
}
