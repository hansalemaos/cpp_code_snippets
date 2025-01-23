#include <cctype>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

static std::vector<size_t> find_all_indices_of_substring(const std::string_view haystack, const std::string_view needle,
                                                         int approx_size = 1024)
{
    std::vector<size_t> indices;
    indices.reserve(approx_size);
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
    return indices;
}

int main()
{
    std::string mystring{"Hello, World!  xHello, World! Hello, World! Hello, World!Hello, World!x"};
    auto vec1{find_all_indices_of_substring(mystring, "Hello", 10)};
    for (const auto &s : vec1)
    {
        std::cout << s << std::endl;
    }

    return 0;
}
