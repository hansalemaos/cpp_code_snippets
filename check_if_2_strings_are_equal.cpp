#include <algorithm>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

bool constexpr compare2strings(const std::string_view s1, const std::string_view s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    while (it1 != s1.end())
    {
        if (*it1 != *it2)
        {
            return false;
        }
        it1++;
        it2++;
    }
    return true;
}

int main()
{
    std::string hello_string{"Hello"};
    std::string hallo_string{"Hallo"};
    std::cout << "Hallo vs. Hello: " << compare2strings("Hallo", "Hello") << std::endl;
    std::cout << "Hello vs. Hello: " << compare2strings("Hello", "Hello") << std::endl;
    std::cout << "hello_string vs. Hello: " << compare2strings(hello_string, "Hello") << std::endl;
    std::cout << "hello_string vs. Hallo: " << compare2strings(hello_string, "Hallo") << std::endl;
    std::cout << "hello_string vs. hallo_string: " << compare2strings(hello_string, hallo_string) << std::endl;
    std::cout << "hello_string vs. hello_string: " << compare2strings(hello_string, hello_string) << std::endl;

    return 0;
}
