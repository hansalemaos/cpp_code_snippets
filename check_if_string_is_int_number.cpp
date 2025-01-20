#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

static constexpr char chars_integer_numbers[] = "0123456789";
static constexpr std::string_view chars_spaces = " \t\n\r\f\v";

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

static bool is_int_number(std::string_view s, bool strip_spaces = true)
{
    if (strip_spaces)
    {
        lstrip_from_string_view(s, chars_spaces);
        rstrip_from_string_view(s, chars_spaces);
    }

    if (s.size() == 0)
    {
        return false;
    };
    if ((s.size() > 1) && ((s[0] == '-') || (s[0] == '+')) && ((s[1] != '-') && (s[1] != '+')))
    {
        return is_int_number(s.substr(1, s.size() - 1));
    }
    for (const char &i : s)
    {
        bool isnumber = false;
        for (const char &j : chars_integer_numbers)
        {
            if (i == j)
            {
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
    std::string mystring = "\n   \tdddd\t sss   \t\nqq\t            ";
    std::string_view mystring_view{mystring};

    lstrip_from_string_view(mystring_view, " \t\n\r\f\v");
    rstrip_from_string_view(mystring_view, " \t\n\r\f\v");

    std::string intno1{"1111223"};
    std::string intno2{"  1111223"};
    std::string intno3{"  1111223  "};
    std::string NOTintno{"  1x1x1x1x2x23  "};

    std::cout << "is_int_number(intno1) = " << is_int_number(intno1) << std::endl;
    std::cout << "is_int_number(intno2) = " << is_int_number(intno2) << std::endl;
    std::cout << "is_int_number(intno3) = " << is_int_number(intno3) << std::endl;
    std::cout << "is_int_number(NOTintno) = " << is_int_number(NOTintno) << std::endl;

    std::cout << "mystring_view = " << mystring_view << std::endl;

    return 0;
}
