#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>
template <typename T> std::vector<std::vector<T>> chunk_vector(std::vector<T> &vec1, size_t chunk_size)
{
    size_t first_loop{(size_t)::ceil((double)(vec1.size()) / (double)(chunk_size))};
    size_t loop_counter{};
    std::vector<std::vector<T>> chunk{};
    for (size_t i{}; i < first_loop; i++)
    {
        chunk.emplace_back();
        chunk.reserve(chunk_size);
        for (size_t j{}; j < chunk_size; j++)
        {
            chunk[i].emplace_back(vec1[loop_counter]);
            loop_counter++;
            if (loop_counter == vec1.size())
            {
                return chunk;
            }
        }
    }
    return chunk;
}

template <typename T>
std::vector<std::vector<T>> chunk_vector_fill(std::vector<T> &vec1, size_t chunk_size, T fill_value)
{
    size_t first_loop{(size_t)::ceil((double)(vec1.size()) / (double)(chunk_size))};
    size_t loop_counter{};
    std::vector<std::vector<T>> chunk{};
    for (size_t i{}; i < first_loop; i++)
    {
        chunk.emplace_back();
        chunk.back().resize(chunk_size, fill_value);
        for (size_t j{}; j < chunk_size; j++)
        {
            chunk[i][j] = vec1[loop_counter];
            loop_counter++;
            if (loop_counter == vec1.size())
            {
                return chunk;
            }
        }
    }
    return chunk;
}

int main()
{

    std::vector<int> vec2{10, 20, 30, 40, 50, 111, 12, 1233, 11, 3};
    auto chunked_vector{chunk_vector(vec2, 3)}; // zip_2_vectors
    for (const auto &vec : chunked_vector)
    {
        for (const auto &val : vec)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    auto chunked_and_filled_vector{chunk_vector_fill(vec2, 3, 4)}; // zip_2_vectors
    for (const auto &vec : chunked_and_filled_vector)
    {
        for (const auto &val : vec)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
