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
void signal_handler(const int signal)
{
    std::cerr << "Caught signal " << signal << std::endl;

    if (signal == SIGINT)
    {
        exit(signal);
    }

    else if (signal == SIGILL)
    {
        // do something here
        exit(signal);
    }
    else if (signal == SIGFPE)
    {
        // do something here
        exit(signal);
    }
    else if (signal == SIGSEGV)
    {
        // do something here
        exit(signal);
    }
    else if (signal == SIGTERM)
    {
        // do something here
        exit(signal);
    }
    else if (signal == SIGBREAK)
    {
        // do something here
        exit(signal);
    }
    else if (signal == SIGABRT)
    {
        // do something here
        exit(signal);
    }
    else if (signal == SIGABRT_COMPAT)
    {
        // do something here
        exit(signal);
    }
    exit(signal);
}

int main()
{
    signal(SIGINT, signal_handler);
    signal(SIGILL, signal_handler);
    signal(SIGFPE, signal_handler);
    signal(SIGSEGV, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGBREAK, signal_handler);
    signal(SIGABRT, signal_handler);
    signal(SIGABRT_COMPAT, signal_handler);

    while (true)
    {
        std::cout << "Hello World";
    }

    return 0;
}
