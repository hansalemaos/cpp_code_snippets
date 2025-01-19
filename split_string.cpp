#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

std::vector<std::string> split_string(std::string &s, const std::string_view splitat)
{
    std::vector<std::string> result;
    auto strs{s | std::views::split(splitat)};
    size_t reserve_size{1};
    for (const auto &ref : strs)
    {
        reserve_size += ref.size();
    }
    result.reserve(reserve_size);
    for (const auto &ref : strs)
    {
        result.emplace_back(std::string{ref.begin(), ref.end()});
    }
    return result;
}
int main()
{
    std::string mystring{"Hello XXAXB WXXorld!"};

    std::cout << mystring << std::endl;
    auto result{split_string(mystring, "XX")};
    for (const auto &ref : result)
    {
        std::cout << ref << std::endl;
    }

    return 0;
}
