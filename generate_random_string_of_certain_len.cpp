#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

static std::string generate_random_alphanumstring(size_t len)
{

    std::string s2(len + 1, 0);
    auto *s = &s2[0];
    for (size_t i = 0; i < len; ++i)
    {
        int random_char = rand() % (26 + 26 + 10);
        if (random_char < 26)
            s[i] = 'a' + random_char;
        else if (random_char < 26 + 26)
            s[i] = 'A' + random_char - 26;
        else
            s[i] = '0' + random_char - 26 - 26;
    }
    return s2;
}
int main()
{
    std::cout << generate_random_alphanumstring(10);
    return 0;
}
