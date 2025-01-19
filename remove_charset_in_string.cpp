#include <iostream>
#include <string>
#include <string_view>

static void constexpr remove_andpercent(std::string &s, const std::string_view &chars)
{
    if (chars.empty() || s.empty())
    {
        return;
    }
    for (const auto &c : chars)
    {
        s.erase(std::remove(s.begin(), s.end(), c), s.end());
    }
}

int main()
{
    std::string mystring{"Hello XXAXB World!"};

    std::cout << mystring << std::endl;
    remove_andpercent(mystring, "XA !");
    std::cout << mystring << std::endl;

    return 0;
}
