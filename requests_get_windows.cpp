#pragma comment(lib, "urlmon.lib")

#include <iosfwd>
#include <iostream>
#include <objidlbase.h>
#include <sstream>
#include <string>
#include <urlmon.h>
#include <windows.h>

static std::string ws2s(std::wstring &str)
{
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0, NULL, NULL);
    std::string strTo(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &str[0], (int)str.size(), &strTo[0], size_needed, NULL, NULL);
    return strTo;
}

static std::wstring s2ws(std::string &str)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

std::string requests_get(std::string &url)
{
    static constexpr int buffersize{32};
    IStream *stream;
    std::wstring converted{s2ws(url)};
    const WCHAR *wc = converted.c_str();
    HRESULT result = URLOpenBlockingStream(0, wc, &stream, 0, 0);
    if (result != 0)
    {
        return "";
    }
    char buffer[buffersize];
    unsigned long bytesRead;
    std::stringstream ss;
    stream->Read(buffer, buffersize, &bytesRead);
    while (bytesRead > 0U)
    {
        ss.write(buffer, (long long)bytesRead);
        stream->Read(buffer, buffersize, &bytesRead);
    }
    stream->Release();
    std::string resultString = ss.str();
    return resultString;
}

int main()
{
    std::string url = "https://www.google.com";
    std::cout << requests_get(url);
    std::string url2 = "https://www.microsoft.com";
    std::cout << requests_get(url2);
}
