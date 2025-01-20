#include <iostream>
#include <string>
#include <string_view>

void constexpr replace_charset_with_char(std::string &s, const std::string_view chars, char c = ' ')
{
    if (chars.empty() || s.empty())
    {
        return;
    }
    for (size_t i{}; i < s.size(); i++)
    {
        for (size_t j{}; j < chars.size(); j++)
        {
            if (s[i] == chars[j])
            {
                s[i] = c;
                break;
            }
        }
    }
}

int main()
{
    std::string mystring{"Hello XXAXB World!"};

    std::cout << mystring << std::endl;
    replace_charset_with_char(mystring, "XA !", 'Q');
    std::cout << mystring << std::endl;

    return 0;
}
