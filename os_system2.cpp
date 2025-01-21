#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <array>
#include <cstdio>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <map>
#include <pthread.h>
#include <ranges>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <string_view>
#include <sys/epoll.h>
#include <sys/wait.h>
#include <thread>
#include <unistd.h>
#include <vector>

typedef struct proc_data
{

    std::string std_out;
    int pid;
    int exit_code;

} p_data;

static pid_t system2(const char *command, int *infp, int *outfp)
{
    int p_stdin[2];
    int p_stdout[2];
    pid_t pid;

    if (pipe(p_stdin) == -1)
        return -1;

    if (pipe(p_stdout) == -1)
    {
        close(p_stdin[0]);
        close(p_stdin[1]);
        return -1;
    }

    pid = fork();

    if (pid < 0)
    {
        close(p_stdin[0]);
        close(p_stdin[1]);
        close(p_stdout[0]);
        close(p_stdout[1]);
        return pid;
    }
    else if (pid == 0)
    {
        close(p_stdin[1]);
        dup2(p_stdin[0], 0);
        close(p_stdout[0]);
        dup2(p_stdout[1], 1);
        dup2(::open("/dev/null", O_RDONLY), 2);
        for (int i = 3; i < 4096; ++i)
            ::close(i);
        setsid();
        execl("/bin/sh", "sh", "-c", command, NULL);
        _exit(1);
    }
    close(p_stdin[0]);
    close(p_stdout[1]);

    if (infp == NULL)
    {
        close(p_stdin[1]);
    }
    else
    {
        *infp = p_stdin[1];
    }

    if (outfp == NULL)
    {
        close(p_stdout[0]);
    }
    else
    {
        *outfp = p_stdout[0];
    }

    return pid;
}

proc_data execute_command_capture_stdout_and_wait(const char *command)
{
    int out_fd;
    auto pid = system2(command, NULL, &out_fd);
    if (pid < 0)
    {
        throw std::runtime_error("Failed to execute command");
    }
    char buffer[128];
    ssize_t bytes_read;
    std::string output;
    output.reserve(1024);
    while ((bytes_read = read(out_fd, buffer, sizeof(buffer) - 1)) > 0)
    {
        for (int i = 0; i < bytes_read; i++)
        {
            output += buffer[i];
            buffer[i] = '\0';
        }
    }
    close(out_fd);
    int status;
    waitpid(pid, &status, 0);
    return proc_data{output, pid, status};
}
int execute_command_no_wait_return_pid(const char *command)
{
    int out_fd;
    auto pid = system2(command, NULL, NULL);
    if (pid < 0)
    {
        throw std::runtime_error("Failed to execute command");
    }
    return pid;
}

int execute_command_wait_return_pid(const char *command)
{
    int out_fd;
    auto pid = system2(command, NULL, NULL);
    if (pid < 0)
    {
        throw std::runtime_error("Failed to execute command");
    }
    int status;
    waitpid(pid, &status, 0);
    return pid;
}

int main(int argc, char **argv)
{
    std::string limit_cmd = "ls -lR";
    int pid_as_int{execute_command_no_wait_return_pid(limit_cmd.c_str())};
    int pid_as_int2{execute_command_wait_return_pid(limit_cmd.c_str())};
    proc_data procd{execute_command_capture_stdout_and_wait(limit_cmd.c_str())};

    std::cout << pid_as_int << std::endl;
    std::cout << pid_as_int2 << std::endl;
    std::cout << "procd" << procd.std_out << std::endl;
    std::cout << "procd" << procd.exit_code << std::endl;
    std::cout << "procd" << procd.pid << std::endl;
    return 0;
}
