#include <cstdio>
#include <cstdlib>
#include <string>
#include <string_view>

static void os_system(const std::string &command)
{
    system(command.c_str());
}
static void os_system(const std::string_view command)
{
    os_system(std::string{command});
}
static void os_system(const char *command)
{
    system(command);
}
int main()
{

    const std::string_view str{"ls"};
    os_system("dir");
    os_system(str);
    return 0;
}
