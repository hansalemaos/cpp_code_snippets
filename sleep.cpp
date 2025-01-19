#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
void sleepcp(int milliseconds);

void sleepcp(int milliseconds)
{
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif // _WIN32
}
void sleepcp(int milliseconds);

int main()
{
    std::cout << "Hello World!" << std::endl;
    sleepcp(1000);
    std::cout << "Hello World!" << std::endl;
    sleepcp(1000);
    std::cout << "Hello World!" << std::endl;
    return 0;
}
