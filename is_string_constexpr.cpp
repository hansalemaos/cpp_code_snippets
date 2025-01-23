#include <cctype>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

static constexpr bool isalnum(const std::string_view str)
{
    std::string::size_type len = str.size();
    std::string::size_type i;
    if (len == 0)
    {
        return false;
    }
    if (len == 1)
    {
        {
            return ::isalnum(str[0]);
        }
    }
    for (i = 0; i < len; ++i)
    {
        if (!::isalnum(str[i]))
        {
            return false;
        }
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////
static constexpr bool isalpha(const std::string_view str)
{
    std::string::size_type len = str.size();
    std::string::size_type i;
    if (len == 0)
    {
        return false;
    }
    if (len == 1)
    {
        return ::isalpha((int)str[0]);
    }
    for (i = 0; i < len; ++i)
    {
        if (!::isalpha((int)str[i]))
        {
            return false;
        }
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////
static constexpr bool isdigit(const std::string_view str)
{
    std::string::size_type len = str.size();
    std::string::size_type i;
    if (len == 0)
    {
        return false;
    }
    if (len == 1)
    {
        return ::isdigit(str[0]);
    }
    for (i = 0; i < len; ++i)
    {
        if (!::isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////
static constexpr bool islower(const std::string_view str)
{
    std::string::size_type len = str.size();
    std::string::size_type i;
    if (len == 0)
    {
        return false;
    }
    if (len == 1)
    {
        return ::islower(str[0]);
    }
    for (i = 0; i < len; ++i)
    {
        if (!::islower(str[i]))
        {
            return false;
        }
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////
static constexpr bool isspace(const std::string_view str)
{
    std::string::size_type len = str.size();
    std::string::size_type i;
    if (len == 0)
    {
        return false;
    }
    if (len == 1)
    {
        return ::isspace(str[0]);
    }
    for (i = 0; i < len; ++i)
    {
        if (!::isspace(str[i]))
        {
            return false;
        }
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////
static constexpr bool istitle(const std::string_view str)
{
    std::string::size_type len = str.size();
    std::string::size_type i;
    if (len == 0)
    {
        return false;
    }
    if (len == 1)
    {
        return ::isupper(str[0]);
    }
    bool cased = false;
    bool previous_is_cased = false;
    for (i = 0; i < len; ++i)
    {
        if (::isupper(str[i]))
        {
            if (previous_is_cased)
            {
                return false;
            }
            previous_is_cased = true;
            cased = true;
        }
        else if (::islower(str[i]))
        {
            if (!previous_is_cased)
            {
                return false;
            }
            previous_is_cased = true;
            cased = true;
        }
        else
        {
            previous_is_cased = false;
        }
    }
    return cased;
}
//////////////////////////////////////////////////////////////////////////////////////////////
static constexpr bool isupper(const std::string_view str)
{
    std::string::size_type len = str.size();
    std::string::size_type i;
    if (len == 0)
    {
        return false;
    }
    if (len == 1)
    {
        return ::isupper(str[0]);
    }
    for (i = 0; i < len; ++i)
    {
        if (!::isupper(str[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string teststring{"Hello World!"};
    std::cout << "islalnum(teststring) = " << isalnum(teststring) << " isalpha " << isalpha(teststring) << std::endl;
    std::cout << "isdigit(teststring) = " << isdigit(teststring) << std::endl;
    std::cout << "islower(teststring) = " << islower(teststring) << std::endl;
    std::cout << "isspace(teststring) = " << isspace(teststring) << std::endl;
    std::cout << "istitle(teststring) = " << istitle(teststring) << std::endl;
    std::cout << "isupper(teststring) = " << isupper(teststring) << std::endl;

    return 0;
}
