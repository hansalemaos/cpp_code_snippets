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

template <typename T> std::vector<T> get_every_n_element_from_vec(std::vector<T> &v, size_t n, bool last_anyway = false)
{

    if (v.size() <= 2)
    {
        return v;
    }
    std::vector<T> resultvec;
    resultvec.reserve((v.size() / n) + 3);
    bool got_last{false};
    for (size_t i{}; i < v.size(); i += n)
    {
        resultvec.emplace_back(v[i]);
        if (i + 1 == v.size())
        {
            got_last = true;
        }
    }
    if (!got_last && last_anyway)
    {
        resultvec.emplace_back(v[v.size() - 1]);
    }
    return resultvec;
}

int main(int argc, char **argv)
{
    std::vector<int> testvector{1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17,
                                18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
                                35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};

    auto brasvec{get_every_n_element_from_vec(testvector, 3)};
    for (const auto &point : brasvec)
    {
        std::cout << point << " ";

        std::cout << std::endl;
    }
    return 0;
}
