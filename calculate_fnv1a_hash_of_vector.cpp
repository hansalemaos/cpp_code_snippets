#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
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
    return fnv1a_hash_int64ptr((size_t)(&(vec.data()[0])), (size_t)(&(vec.data()[0])) + sizeof(T) * vec.size());
}

template <typename T> std::vector<T> remove_duplicated_containers_in_vector(std::vector<T> &v)
{
    std::unordered_map<uint64_t, size_t> seen;
    seen.reserve(v.size());
    auto it = v.begin();
    size_t counter{0};
    while (it != v.end())
    {
        seen[get_hash_from_vector(*it)] = counter;
        counter++;
        it++;
    }
    std::vector<T> resultvec;
    resultvec.reserve(seen.size());
    auto it2 = seen.begin();
    while (it2 != seen.end())
    {
        resultvec.emplace_back(v[it2->second]);
        it2++;
    }
    return resultvec;
}

int main()
{
    std::vector<std::vector<int>> vectest0{{1, 2}, {1, 3}, {1, 3}, {1, 3}, {1, 4},
                                           {1, 2}, {1, 3}, {1, 3}, {1, 3}, {1, 4}};

    auto withoutduplicates{remove_duplicated_containers_in_vector(vectest0)};
    for (auto &i : withoutduplicates)
    {
        for (auto &j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

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
