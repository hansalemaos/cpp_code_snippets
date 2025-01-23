#include <cctype>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

std::vector<std::string> split_string_at_whitespace(const std::string_view str, int maxsplit, int approx_size = 1024)
{
    std::vector<std::string> result;
    result.reserve(approx_size);
    std::string::size_type i;
    std::string::size_type j;
    std::string::size_type len = str.size();
    for (i = j = 0; i < len;)
    {
        while (i < len && ::isspace(str[i]))
        {
            i++;
        }
        j = i;
        while (i < len && !::isspace(str[i]))
        {
            i++;
        }
        if (j < i)
        {
            if (maxsplit-- <= 0)
            {
                break;
            }
            result.emplace_back(std::string(str.substr(j, i - j)));
            while (i < len && ::isspace(str[i]))
            {
                i++;
            }
            j = i;
        }
    }
    if (j < len)
    {
        result.emplace_back(std::string(str.substr(j, len - j)));
    }
    return result;
}

int main()
{
    std::string mystring{"Hello, World!  xx"};
    auto vec1{split_string_at_whitespace(mystring, 1)};
    auto vec2{split_string_at_whitespace(mystring, 100000)};
    for (const auto &s : vec1)
    {
        std::cout << s << std::endl;
    }
    for (const auto &s : vec2)
    {
        std::cout << s << std::endl;
    }
    return 0;
}
