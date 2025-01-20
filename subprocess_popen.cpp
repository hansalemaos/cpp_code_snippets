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

FILE *subprocess_popen(const std::string &cmd)
{

    return EXEC_CMD(cmd.c_str(), "r");
}
FILE *subprocess_popen(const std::string_view cmd)
{
    std::string tmp{cmd};
    return EXEC_CMD(tmp.c_str(), "r");
}
FILE *subprocess_popen(const char *cmd)
{

    return EXEC_CMD(cmd, "r");
}
int main()
{

    FILE *f = subprocess_popen("dir");
    CLOSE_CMD(f);
    return 0;
}
