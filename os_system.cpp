#include <cstdio>
#include <cstdlib>
#include <string>
#include <string_view>

void os_system(const std::string &command)
{
    system(command.c_str());
}
void os_system(const std::string_view command)
{
    os_system(std::string{command});
}
void os_system(const char *command)
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
