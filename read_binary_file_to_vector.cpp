#define _CRT_SECURE_NO_WARNINGS
#include <cerrno>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<char> get_binary_file_contents(const std::string &filename)
{
    std::ifstream in(filename.c_str(), std::ios::in | std::ios::binary);
    if (in)
    {
        std::vector<char> contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return contents;
    }
    throw(std::runtime_error("Could not open file"));
}

int main()
{
    auto result{get_binary_file_contents("C:\\testreadfile.txt")};
    for (const auto &line : result)
    {
        std::cout << line << std::endl;
    }
    return 0;
}
