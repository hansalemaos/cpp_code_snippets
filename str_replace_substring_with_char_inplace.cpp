#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

static void constexpr replace_substring_with_char_inplace(std::string &haystack, const std::string_view needle,
                                                          char c = ' ')
{
    std::vector<size_t> indices;
    size_t offset = 0;
    size_t newoffset = 0;
    size_t maxlen = haystack.size();
    for (;;)
    {
        newoffset = haystack.substr(offset, maxlen).find(needle);
        if (newoffset == std::string::npos)
            break;
        offset += newoffset;
        indices.push_back(offset);
        maxlen = haystack.size() - offset - needle.size();
        offset += needle.size();
    }
    for (auto i : indices)
    {
        for (size_t j = 0; j < needle.size(); j++)
        {
            haystack[i + j] = c;
        }
    }
}
int main()
{

    std::string test1{"0x1234!!!2"};
    std::string test2{"0x12\4\5xx\34"};
    std::string test3{"0x12hf234"};
    std::string test4{"0x1f234"};
    std::string test5{"123.4"};
    std::string test6{"0X1234"};
    std::string test7{"0x1  234"};
    std::string test8{"0X1234"};

    replace_substring_with_char_inplace(test1, "12", 'W');
    std::cout << test1 << '\n';
    replace_substring_with_char_inplace(test2, "12", 'W');
    std::cout << test2 << '\n';
    replace_substring_with_char_inplace(test3, "12", 'W');
    std::cout << test3 << '\n';
    replace_substring_with_char_inplace(test4, "12", 'W');
    std::cout << test4 << '\n';
    replace_substring_with_char_inplace(test5, "12", 'W');
    std::cout << test5 << '\n';
    replace_substring_with_char_inplace(test6, "12", 'W');
    std::cout << test6 << '\n';
    replace_substring_with_char_inplace(test7, "12", 'W');
    std::cout << test7 << '\n';
    replace_substring_with_char_inplace(test8, "12", 'W');
    std::cout << test8 << '\n';

    return 0;
}
