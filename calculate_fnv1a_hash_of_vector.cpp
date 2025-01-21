#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

static constexpr uint64_t FNV_OFFSET_BASIS = 0xcbf29ce484222325;
static constexpr uint64_t FNV_PRIME = 0x100000001b3;
uint64_t constexpr fnv1a_hash_int64ptr(size_t startaddress, size_t endaddress)
{

    uint64_t hash = FNV_OFFSET_BASIS;
    uint8_t *startpointer{(uint8_t *)startaddress};
    uint8_t *endpointer{(uint8_t *)endaddress};
    size_t i = 0;
    for (; startpointer != endpointer;)
    {
        uint8_t byte = ((*startpointer) >> (i * 8)) & 0xFF;
        hash ^= byte;
        hash *= FNV_PRIME;
        i++;
        startpointer++;
    }

    return hash;
}

template <typename T> uint64_t get_hash_from_vector(std::vector<T> &vec)
{
    return fnv1a_hash_int64ptr((size_t)(&(vec.data()[0])), (size_t)(&(vec.data()[0])) + vec.size());
}
int main()
{
    std::vector<std::pair<int, int>> vectest{
        std::make_pair(1, 2), std::make_pair(1, 3), std::make_pair(1, 3), std::make_pair(1, 3), std::make_pair(1, 4),
    };

    auto hash1{get_hash_from_vector(vectest)};
    std::cout << hash1 << std::endl;

    std::vector<std::pair<int, int>> vectest2{
        std::make_pair(1, 2), std::make_pair(1, 3), std::make_pair(1, 3), std::make_pair(1, 3), std::make_pair(1, 4),
    };
    auto hash2{get_hash_from_vector(vectest2)};
    std::cout << hash2 << std::endl;
    return 0;
}
