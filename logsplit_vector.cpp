#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

template <typename T> std::vector<std::vector<T>> logsplit_vector(std::vector<T> &lst)
{
    std::vector<std::vector<T>> result;
    result.reserve(::ceil(::sqrt(lst.size())) + 1);
    auto it = lst.begin();
    int n = 0;

    while (it != lst.end())
    {
        std::vector<T> chunk;
        chunk.reserve(n + 1);
        chunk.emplace_back(*it);
        ++it;

        for (int i{}; i < n && it != lst.end(); ++i)
        {
            chunk.emplace_back(*it);
            ++it;
        }

        result.emplace_back(chunk);
        ++n;
    }
    return result;
}

int main(int argc, char **argv)
{
    std::vector<int> testvector{1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17,
                                18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
                                35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};

    auto brasvec{logsplit_vector(testvector)};
    for (const auto &point : brasvec)
    {
        for (const auto &point2 : point)
        {
            std::cout << point2 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
