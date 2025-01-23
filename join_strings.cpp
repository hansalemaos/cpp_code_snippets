#include <cctype>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

std::string join_strings(const std::string &str, const std::vector<std::string> &seq)
{
    std::vector<std::string>::size_type seqlen{seq.size()};
    std::vector<std::string>::size_type i;
    if (!seqlen)
    {
        return "";
    }
    if (seqlen == 1)
    {
        return seq[0];
    }
    std::string result(seq[0]);
    for (i = 1; i < seqlen; ++i)
    {
        result += str + seq[i];
    }
    return result;
}

int main()
{
    std::vector<std::string> v{"a", "b", "c", "d", "e"};
    auto result{join_strings(",", v)};
    std::cout << result << std::endl;

    return 0;
}
