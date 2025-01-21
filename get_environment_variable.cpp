#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

std::string static get_env(std::string &&key, const std::string_view nan_value = "NOT_FOUND")
{
    if (key.empty())
    {
        return std::string{nan_value};
    }
    const char *ev_val{getenv(key.c_str())};
    if (ev_val == nullptr)
    {
        return std::string{nan_value};
    }
    return std::string{ev_val};
}

const char *get_env(const char *tag, const char *def) noexcept
{
    const char *ret = std::getenv(tag);
    return ret ? ret : def;
}

int main()
{
    const char *env = get_env("ADB_LOCAL_TRANSPORT_MAX_PORT", nullptr);
    std::string env2 = get_env("ADB_LOCAL_TRANSPORT_MAX_PORT", "NOT_FOUND");
    if (env == nullptr)
    {
        std::cout << "NULL" << std::endl;
    }
    else
    {
        std::cout << env << std::endl;
    }
    std::cout << env2 << std::endl;
    return 0;
}
