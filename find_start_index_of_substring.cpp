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

constexpr int find_start_index_of_substring(const std::string_view haystack, const std::string_view needle)
{
    size_t start_index = haystack.find(needle);
    if (start_index == std::string::npos)
    {
        return -1;
    }
    return (int)start_index;
}

int main()
{
    std::string mystring1{"Hello World!"};
    std::string mystring2{"       Hello World!"};
    std::cout << find_start_index_of_substring(mystring2, mystring1) << std::endl;
    return 0;
}
