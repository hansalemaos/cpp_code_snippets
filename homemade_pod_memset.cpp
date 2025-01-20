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

static void constexpr mymemsetptrloop(uint8_t *startptr, uint8_t *endptr)
{
    for (; startptr != endptr; startptr++)
    {
        *startptr = 0;
    }
}
template <typename T> void constexpr mymemset(T &element)
{
    size_t size{sizeof(T)};

    mymemsetptrloop(reinterpret_cast<uint8_t *>(&element), reinterpret_cast<uint8_t *>(&element) + size);
}

int main()
{
    typedef struct rs
    {
        int64_t pod1;
        size_t pod2;
        float pod3;
        char pod[32];
    } rs;
    rs result_struct{1234, 2, 3.14, "Hello!"};
    std::cout << result_struct.pod1 << " " << result_struct.pod2 << " " << result_struct.pod3 << " "
              << result_struct.pod << std::endl;
    mymemset(result_struct);
    std::cout << result_struct.pod1 << " " << result_struct.pod2 << " " << result_struct.pod3 << " "
              << result_struct.pod << std::endl;

    return 0;
}
