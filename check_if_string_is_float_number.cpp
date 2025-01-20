#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

static constexpr std::string_view chars_spaces = " \t\n\r\f\v";
static constexpr std::string_view chars_float_numbers_string_view = "0123456789.";

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

static constexpr void rstrip_from_string_view(std::string_view &s, const std::string_view &strip_chars)
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

static bool is_float_number(std::string_view s, bool strip_spaces = true)
{

    if (s.size() == 0)
    {
        return false;
    };
    if (strip_spaces)
    {
        lstrip_from_string_view(s, chars_spaces);
        rstrip_from_string_view(s, chars_spaces);
        if (s.size() == 0)
        {
            return false;
        };
    }
    if ((s.size() > 1) && ((s[0] == '-') || (s[0] == '+')) && ((s[1] != '-') && (s[1] != '+')))
    {
        return is_float_number(s.substr(1, s.size() - 1));
    }
    size_t dotcounter = 0;
    for (const char &i : s)
    {
        bool isnumber = false;
        for (const char &j : chars_float_numbers_string_view)
        {
            if (i == j)
            {
                if (i == '.')
                {
                    dotcounter += 1;
                    if (dotcounter > 1)
                    {
                        return false;
                    }
                }
                isnumber = true;
                break;
            }
        }
        if (!isnumber)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    std::string intno1{"1111223.33"};
    std::string intno2{"  1111223.44"};
    std::string intno3{"  1111223.111  "};
    std::string NOTintno{"  1x1x1x1x2.11x23  "};

    std::cout << "is_int_number(intno1) = " << is_float_number(intno1) << std::endl;
    std::cout << "is_int_number(intno2) = " << is_float_number(intno2) << std::endl;
    std::cout << "is_int_number(intno3) = " << is_float_number(intno3) << std::endl;
    std::cout << "is_int_number(NOTintno) = " << is_float_number(NOTintno) << std::endl;

    return 0;
}
