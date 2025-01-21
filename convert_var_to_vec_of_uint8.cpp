#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <any>
#include <array>
#include <cctype>
#include <cmath>
#include <compare>
#include <cstring>
#include <deque>
#include <filesystem>
#include <forward_list>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <signal.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <string_view>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>

template <typename T> std::vector<uint8_t> convert_to_uint8_vec(T &var)
{
    uint8_t *startptr{(uint8_t *)&var};
    size_t size{sizeof(T)};
    uint8_t *endptr{startptr + size};
    std::vector<uint8_t> cstring2hex;
    cstring2hex.reserve(size);
    for (; startptr != endptr; startptr++)
    {
        cstring2hex.emplace_back(*startptr);
    }
    return cstring2hex;
}

int main()
{
    int myint{1234};
    auto v1{convert_to_uint8_vec(myint)};
    float myfloat{1234.44};
    auto v2{convert_to_uint8_vec(myfloat)};
    for (auto &i : v1)
    {
        std::cout << (int)i;
    }
    std::cout << std::endl;
    for (auto &i : v2)
    {
        std::cout << (int)i;
    }
    std::cout << std::endl;
    return 0;
}
