#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

static constexpr void lstrip_from_string_view(std::string_view &s, const std::string_view &strip_chars)
{
    if (s.size() == 0)
    {
        return;
    };
    size_t prefix_counter{};
    for (size_t i{}; i < s.size(); i++)
    {
        bool found_something = false;
        for (size_t j{}; j < strip_chars.size(); j++)
        {
            if (s[i] == strip_chars[j])
            {
                found_something = true;
                prefix_counter++;
                break;
            }
        }
        if (!found_something)
        {
            break;
        }
    }
    if (prefix_counter > 0)
    {
        s.remove_prefix(prefix_counter);
    }
}

static void rstrip_from_string_view(std::string_view &s, const std::string_view &strip_chars)
{
    if (s.size() == 0)
    {
        return;
    };
    size_t suffix_counter{};
    for (int i{(int)(s.size() - 1)}; i >= 0; i--)
    {
        bool found_something = false;
        for (int j{(int)(strip_chars.size() - 1)}; j >= 0; j--)
        {
            if (s[i] == strip_chars[j])
            {
                found_something = true;
                suffix_counter++;
                break;
            }
        }
        if (!found_something)
        {
            break;
        }
    }
    if (suffix_counter > 0)
    {
        s.remove_suffix(suffix_counter);
    }
}

int main()
{
    std::string mystring = "\n   \tdddd\t sss   \t\nqq\t            ";
    std::string_view mystring_view{mystring};

    lstrip_from_string_view(mystring_view, " \t\n\r\f\v");
    rstrip_from_string_view(mystring_view, " \t\n\r\f\v");

    std::cout << "mystring_view = " << mystring_view << std::endl;

    return 0;
}
