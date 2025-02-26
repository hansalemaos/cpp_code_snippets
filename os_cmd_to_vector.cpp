#define _CRT_SECURE_NO_WARNINGS
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <vector>
#ifdef _WIN32
#include <windows.h>

#define EXEC_CMD(command, mode) _popen(command, mode)
#define CLOSE_CMD(pipe) _pclose(pipe)
#else
#include <unistd.h>
#define EXEC_CMD(command, mode) popen(command, mode)
#define CLOSE_CMD(pipe) pclose(pipe)
#endif
#include <cstdio>
#include <string>
int main()
{
    std::vector<char> buffer;
    size_t buffsize = 8;
    buffer.resize(buffsize);
    std::string cmd = "dir";
    FILE *f = EXEC_CMD(cmd.c_str(), "r");
    if (f == NULL)
    {
        return EXIT_FAILURE;
    }
    size_t offset = 0;
    while (fgets(buffer.data() + offset, buffsize, f) != NULL)
    {
        buffer.resize(buffer.size() + buffsize);
        offset += buffsize;
    }
    CLOSE_CMD(f);
    for (int i = 0; i < buffer.size(); i++)
    {
        std::cout << buffer[i];
    }
    return EXIT_SUCCESS;
}
