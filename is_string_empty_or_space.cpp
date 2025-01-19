#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

static bool constexpr isspace_or_empty(const std::string_view str)
{
    if (str.size() == 0)
    {
        return true;
    }
    for (size_t i{}; i < str.size(); i++)
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r' && str[i] != '\v' && str[i] != '\f')
        {
            return false;
        }
    }
    return true;
}

int main()
{

    std::cout << isspace_or_empty(" ") << std::endl;
    std::cout << isspace_or_empty(" xxx") << std::endl;

    return 0;
}
