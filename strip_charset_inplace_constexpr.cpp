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

void constexpr lstrip_spaces_inplace(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); }));
}

void constexpr rstrip_spaces_inplace(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
}
void constexpr strip_spaces_inplace(std::string &s)
{
    lstrip_spaces_inplace(s);
    rstrip_spaces_inplace(s);
}

void constexpr lstrip_charset_inplace(std::string &s, const std::string_view char_set)
{
    if (s.size() == 0 || char_set.size() == 0)
    {
        return;
    }
    size_t newsize{};
    size_t oldsize = s.size();
    while (newsize < oldsize)
    {
        newsize = s.size();
        oldsize = newsize;
        for (auto c : char_set)
        {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), [c = c](char ch) { return ch != c; }));
        }
        newsize = s.size();
    }
}
void constexpr rstrip_charset_inplace(std::string &s, const std::string_view char_set)
{
    if (s.size() == 0 || char_set.size() == 0)
    {
        return;
    }
    size_t newsize{};
    size_t oldsize = s.size();
    while (newsize < oldsize)
    {
        newsize = s.size();
        oldsize = newsize;
        for (auto c : char_set)
        {
            s.erase(std::find_if(s.rbegin(), s.rend(), [c = c](char ch) { return ch != c; }).base(), s.end());
        }
        newsize = s.size();
    }
}
void constexpr strip_charset_inplace(std::string &s, const std::string_view char_set)
{
    lstrip_charset_inplace(s, char_set);
    rstrip_charset_inplace(s, char_set);
}
int main()
{

    std::string test1{" x x   hello  x "};
    lstrip_charset_inplace(test1, " x");
    std::cout << test1 << std::endl;
    rstrip_charset_inplace(test1, " x");
    std::cout << test1 << std::endl;
    strip_charset_inplace(test1, "loh");
    return 0;
}
