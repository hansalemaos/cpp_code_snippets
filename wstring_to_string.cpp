#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <string>
#include <string_view>

std::string ws2s(std::wstring &str)
{
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0, NULL, NULL);
    std::string strTo(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &str[0], (int)str.size(), &strTo[0], size_needed, NULL, NULL);
    return strTo;
}

std::wstring s2ws(std::string &str)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

int main()
{

    std::string str{"Hello World!"};

    std::wstring wstr = s2ws(str);
    std::cout << ws2s(wstr) << std::endl;

    return 0;
}
