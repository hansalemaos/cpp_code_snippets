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

constexpr int count_leading_spaces(const std::string_view line)
{
    int count = 0;
    for (char c : line)
    {
        if (c == ' ')
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return (int)count;
}

int main()
{
    std::string mystring{"Hello World!"};
    std::cout << count_leading_spaces(mystring) << std::endl;
    std::string mystring1{"       Hello World!"};
    std::cout << count_leading_spaces(mystring1) << std::endl;
    return 0;
}
