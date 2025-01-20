#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <variant>

static constexpr std::string_view zero1 = "0";
static constexpr std::string_view zero2 = "0.0";
static constexpr std::string_view zero3 = ".0";
static constexpr std::string_view zero4 = "-0";
static constexpr std::string_view zero5 = "-0.0";
static constexpr std::string_view zero6 = "+0.0";
static constexpr char chars_integer_numbers[] = "0123456789";

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

static bool is_int_number(std::string_view s, bool strip_spaces = true)
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

static bool check_if_string_is_valid_int_zero(const std::string_view str)
{

    if ((str == zero1) || (str == zero2) || (str == zero3) || (str == zero4) || (str == zero5) || (str == zero6))
    {
        return true;
    }

    size_t strlen = str.size();

    if (strlen == 0)
    {
        return false;
    }
    if ((strlen > 1) && (str[0] == '+') && (is_float_number(str.substr(1, strlen - 1))))
    {
        return (int(atof(&str.data()[1])) == 0);
    }
    if ((strlen > 1) && (str[0] == '-') && (is_float_number(str.substr(1, strlen - 1))))
    {
        return ((atof(&str.data()[1])) == 0);
    }
    if (is_int_number(str))
    {
        return (int(atof(str.data())) == 0);
    }

    if ((str[0] != '0') && (str[0] != '.'))
    {
        return false;
    }
    if ((str[0] == '.') && (strlen == 1))
    {
        return false;
    }

    if (str[0] == '.')
    {
        return is_int_number(str.substr(1, strlen - 1));
    }
    if ((str[0] == '0') && (strlen == 1))
    {
        return true;
    }
    if (is_float_number(str))
    {
        double tempdouble = atof(str.data());
        return (tempdouble < 1) && (tempdouble >= 0);
    }
    return false;
}

static std::variant<double, int64_t> to_float_or_int(std::string_view s)
{
    std::variant<double, int64_t> returnvalue{};
    std::string tmpstring = std::string(s);
    if (is_int_number(s))
    {
        returnvalue = std::stoll(tmpstring);
    }
    else if (is_float_number(s))
    {
        returnvalue = std::stod(tmpstring);
    }
    return returnvalue;
}
static bool check_if_string_is_valid_float_zero(const std::string_view str)
{

    if (is_float_number(str))
    {
        if (atof(str.data()) == 0)
        {
            return true;
        }
    }
    size_t strlen = str.size();
    if ((strlen > 1) && (str[0] == '+') && (is_float_number(str.substr(1, strlen - 1))))
    {
        return ((atof(&str.data()[1])) == 0);
    }
    if ((strlen > 1) && (str[0] == '-') && (is_float_number(str.substr(1, strlen - 1))))
    {
        return ((atof(&str.data()[1])) == 0);
    }
    return false;
}

int64_t convert_to_int_at_any_cost(std::string_view _sv, int64_t nan_value, bool strip_spaces = true)
{
    if (_sv.size() == 0)
    {
        return nan_value;
    };
    if (strip_spaces)
    {
        lstrip_from_string_view(_sv, chars_spaces);
        rstrip_from_string_view(_sv, chars_spaces);
        if (_sv.size() == 0)
        {
            return nan_value;
        };
    }
    std::variant<double, int64_t> tmpvalue = to_float_or_int(_sv);
    int64_t tmpnumber;
    try
    {
        tmpnumber = std::get<int64_t>(tmpvalue);
    }
    catch (...)
    {
        try
        {
            tmpnumber = (int64_t)(std::get<double>(tmpvalue));
        }
        catch (...)
        {
            // do nothing
        }
    }

    if (tmpnumber != 0)
    {
        return tmpnumber;
    }
    if ((tmpnumber == 0) && (check_if_string_is_valid_int_zero(_sv)))
    {
        return 0;
    }

    return nan_value;
}
double convert_to_double_at_any_cost(std::string_view _sv, double nan_value, bool strip_spaces = true)
{
    if (_sv.size() == 0)
    {
        return nan_value;
    };
    if (strip_spaces)
    {
        lstrip_from_string_view(_sv, chars_spaces);
        rstrip_from_string_view(_sv, chars_spaces);
        if (_sv.size() == 0)
        {
            return nan_value;
        };
    }
    std::variant<double, int64_t> tmpvalue = to_float_or_int(_sv);
    double tmpnumber;
    try
    {
        tmpnumber = std::get<double>(tmpvalue);
    }
    catch (...)
    {
        try
        {
            tmpnumber = (double)(std::get<int64_t>(tmpvalue));
        }
        catch (...)
        {
            // do nothing
        }
    }
    if (tmpnumber != 0)
    {
        return tmpnumber;
    }
    if ((tmpnumber == 0) && (check_if_string_is_valid_float_zero(_sv)))
    {
        return 0;
    }

    return nan_value;
}

int main()
{

    std::string intno1{"123.33  "};
    std::string intno2{"  2.44"};
    std::string intno3{"  111  "};
    std::string NOTintno{"  1x1x1x1x2.11x23    "};
    int64_t my_nan_value = -1;
    std::cout << convert_to_int_at_any_cost(intno1, my_nan_value) << std::endl;
    std::cout << convert_to_int_at_any_cost(intno2, my_nan_value) << std::endl;
    std::cout << convert_to_int_at_any_cost(intno3, my_nan_value) << std::endl;
    std::cout << convert_to_int_at_any_cost(NOTintno, my_nan_value) << std::endl;
    std::cout << convert_to_double_at_any_cost(intno1, my_nan_value) << std::endl;
    std::cout << convert_to_double_at_any_cost(intno2, my_nan_value) << std::endl;
    std::cout << convert_to_double_at_any_cost(intno3, my_nan_value) << std::endl;
    std::cout << convert_to_double_at_any_cost(NOTintno, my_nan_value) << std::endl;
    return 0;
}
