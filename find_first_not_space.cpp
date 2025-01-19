#include <array>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

static constexpr size_t find_first_that_is_not_space(const std::string_view st)
{
    if (st.empty())
    {
        return std::string::npos;
    }
    return st.find_first_not_of(" \t\n\r\v\f");
}

int main()
{
    std::cout << find_first_that_is_not_space("hello  hello");
    std::cout << find_first_that_is_not_space("   hello  hello");

    return 0;
}
