#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

template <typename T, typename U> std::vector<std::pair<T, U>> zip_2_vectors(std::vector<T> &vec1, std::vector<U> &vec2)
{
    size_t loop_size = std::min(vec1.size(), vec2.size());
    std::vector<std::pair<T, U>> result;
    result.reserve(loop_size);
    for (size_t i = 0; i < loop_size; ++i)
    {
        result.emplace_back(std::make_pair(vec1[i], vec2[i]));
    }
    return result;
}

int main()
{

    std::vector vec1{1, 2, 3, 4, 5};
    std::vector vec2{10, 20, 30, 40, 50, 111, 12};
    auto zippedvec{zip_2_vectors(vec1, vec2)}; // zip_2_vectors
    for (const auto &pair : zippedvec)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    return 0;
}
