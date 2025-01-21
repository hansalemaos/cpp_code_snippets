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

static constexpr int8_t hex_upper_letters[] = "0123456789ABCDEF";

template <typename T> std::string convert_to_base16_string(T &var)
{
    uint8_t *startptr{(uint8_t *)&var};
    size_t size{sizeof(T)};
    uint8_t *endptr{startptr + size};
    std::string cstring2hex(size * 2, '0');
    auto buf = cstring2hex.data();
    for (; startptr != endptr; startptr++)
    {
        *buf++ = hex_upper_letters[(*startptr) >> 4];
        *buf++ = hex_upper_letters[(*startptr) & 0x0F];
    }
    return cstring2hex;
}
std::vector<uint8_t> convert_base16_string_to_bytes(std::string &str)
{
    std::vector<uint8_t> cstring2hex;
    cstring2hex.reserve((str.size() / 2) + 2);
    uint8_t result{};
    for (size_t i = 0; i < str.size(); i += 2)
    {
        std::string cstri = str.substr(i, 2);

        std::from_chars(str.data() + i, str.data() + i + 2, result, 16);
        cstring2hex.emplace_back(result);
    }
    return cstring2hex;
}

int main()
{
    int myint{1234};
    std::string converted1{convert_to_base16_string(myint)};
    float myfloat{1234.44};
    std::string converted2{convert_to_base16_string(myfloat)};
    std::vector<uint8_t> v1{convert_base16_string_to_bytes(converted1)};
    std::vector<uint8_t> v2{convert_base16_string_to_bytes(converted2)};
    std::cout << converted1 << " " << (*(int *)v1.data()) << std::endl;
    std::cout << converted2 << " " << (*(float *)v2.data()) << std::endl;

    return 0;
}
