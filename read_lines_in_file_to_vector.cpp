#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>
std::vector<std::string> read_lines_in_file_to_vector(const std::string &path, size_t aprox_size = 1024)
{
    std::vector<std::string> result_vector;
    result_vector.reserve(aprox_size);
    std::ifstream file{path, std::ios::in};
    if (!file)
    {
        return result_vector;
    }
    std::string line;
    while (std::getline(file, line))
    {

        result_vector.push_back(line);
    }

    file.close();
    return result_vector;
}

int main()
{
    auto result{read_lines_in_file_to_vector("C:\\testreadfile.txt", 1024)};
    for (const auto &line : result)
    {
        std::cout << line << std::endl;
    }
    return 0;
}
