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

template <typename T> std::string dump_vec_of_vecs_as_csv(std::vector<std::vector<T>> v, size_t aprox_line_size = 1024)
{
    std::string outstring;
    outstring.reserve(v.size() * aprox_line_size);
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[i].size(); j++)
        {
            outstring.append(std::format("\"{}\",", v[i][j]));
        }
        outstring.back() = '\n';
    }
    return outstring;
}
int main()
{

    std::vector<std::vector<int>> v{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::cout << dump_vec_of_vecs_as_csv(v) << std::endl;

    std::vector<std::vector<std::string>> v2{{"1x", "21", "3xsd"}, {"45", "5", "6"}, {"7qd", "x8", "9"}};

    std::cout << dump_vec_of_vecs_as_csv(v2) << std::endl;
    return 0;
}
