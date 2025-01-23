#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

template <typename T> std::string convert_mem_address_to_py_bytes_repr_string(T *startptr, size_t length)
{

    char *cptr = (char *)startptr;
    char *endptr = cptr + length;
    std::string newstr;
    newstr.reserve(length * 2);
    while (cptr != endptr)
    {
        if (*cptr == '\t')
        {
            newstr += "\\t";
        }
        else if (*cptr == '\n')
        {
            newstr += "\\n";
        }
        else if (*cptr == '\r')
        {
            newstr += "\\r";
        }
        else if (*cptr < ' ' || *cptr > '~')
        {
            newstr += '\\';
            newstr += 'x';
            if (*cptr < 10)
            {
                newstr += '0';
            }
            newstr.append(std::to_string((int)(*cptr)));
        }
        else
        {
            newstr += *cptr;
        }
        cptr++;
    }
    return newstr;
}

int main()
{
    std::string teststring{
        "hello world hello worldhello world hello worl\3\2dhello world hello \tworldhello world hello "
        "worldhello world hello worldhel\t\rlo world hello worldhe\4llo world hello world"};
    std::cout << convert_mem_address_to_py_bytes_repr_string(teststring.data(), teststring.size());

    return 0;
}
