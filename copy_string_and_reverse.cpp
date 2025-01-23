#include <iostream>
#include <string>
#include <string_view>
#include <vector>

std::string copy_string_and_reverse(const std::string &s)
{
    std::string result = s;
    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    std::string mystring = "Hello, World!";
    std::cout << "Original string: " << mystring << std::endl;
    std::string reversed_string = copy_string_and_reverse(mystring);
    std::cout << "Reversed string: " << reversed_string << std::endl;
    return 0;
}
