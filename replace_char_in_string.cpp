#include <iostream>
#include <string>

void static constexpr replace_char_with_another(std::string &s, char char_old, char char_new,
                                                size_t max_count = std::string::npos)
{
    size_t counter = 0;
    for (size_t i = 0; i < s.size() && counter < max_count; ++i)
    {
        if (s[i] == char_old)
        {
            s[i] = char_new;
            counter++;
        }
    }
}

int main()
{
    std::string mystring{"Hello World!Hello World!Hello World!Hello World!"};

    std::cout << mystring << std::endl;
    replace_char_with_another(mystring, 'H', 'h', 2);
    std::cout << mystring << std::endl;
    replace_char_with_another(mystring, 'o', 'O');
    std::cout << mystring << std::endl;

    return 0;
}
