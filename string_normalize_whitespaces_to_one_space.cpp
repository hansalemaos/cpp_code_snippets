#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

std::string normalize_whitespaces(const std::string_view invecj)
{
    if (invecj.size() == 0)
    {
        return std::string{};
    }
    std::string out_string;
    out_string.reserve(invecj.size());
    int last_whitespace_counter = 1;
    for (size_t i = 0; i < invecj.size(); i++)
    {
        if ((last_whitespace_counter == 0) && ((invecj[i] == ' ') || (invecj[i] == '\t') || (invecj[i] == '\n') ||
                                               (invecj[i] == '\r') || (invecj[i] == '\v') || (invecj[i] == '\f')))
        {
            out_string += ' ';
            last_whitespace_counter += 1;
            continue;
        }
        else if ((last_whitespace_counter != 0) && ((invecj[i] == ' ') || (invecj[i] == '\t') || (invecj[i] == '\n') ||
                                                    (invecj[i] == '\r') || (invecj[i] == '\v') || (invecj[i] == '\f')))
        {
            last_whitespace_counter += 1;
            continue;
        }
        last_whitespace_counter = 0;
        out_string += invecj[i];
    }
    if ((!out_string.empty()) && (out_string.back() == ' '))
    {
        out_string.resize(out_string.size() - 1);
    }

    return out_string;
}

int main()
{

    std::string intno1{"1111223.33"};
    std::string intno2{"  111122   3.44"};
    std::string intno3{"  11112   23.111  "};
    std::string NOTintno{"  1x1x1x1x2.11x23    "};

    std::cout << normalize_whitespaces(intno1) << std::endl;
    std::cout << normalize_whitespaces(intno2) << std::endl;
    std::cout << normalize_whitespaces(intno3) << std::endl;
    std::cout << normalize_whitespaces(NOTintno) << std::endl;

    return 0;
}
