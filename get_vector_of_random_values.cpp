#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <ranges>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <string_view>
#include <thread>
#include <type_traits>
#include <utility>
#include <vector>

template <typename T> std::vector<T> generate_vec_of_random_numbers(T minimal, T maximal, size_t n)
{
    std::vector<T> v;
    v.reserve(n);

    std::random_device rd;
    std::mt19937 engine(rd());

    if constexpr (std::is_integral<T>::value)
    {
        std::uniform_int_distribution<T> dist(minimal, maximal);
        for (size_t i{}; i < n; i++)
        {
            v.emplace_back(dist(engine));
        }
    }
    else if constexpr (std::is_floating_point<T>::value)
    {
        std::uniform_real_distribution<T> dist(minimal, maximal);
        for (size_t i{}; i < n; i++)
        {
            v.emplace_back(dist(engine));
        }
    }

    return v;
}

int main(int argc, char **argv)
{
    std::vector<int> brasvec{generate_vec_of_random_numbers(0, 1000, 100)};

    for (const auto &point : brasvec)
    {
        std::cout << point << " ";

        std::cout << std::endl;
    }
    std::vector<double> brasvec2{generate_vec_of_random_numbers(0.11, 1000.03, 100)};

    for (const auto &point : brasvec2)
    {
        std::cout << point << " ";

        std::cout << std::endl;
    }
    return 0;
}
