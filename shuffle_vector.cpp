#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
static auto rng = std::default_random_engine{};

template <typename T> void shuffle_vector(std::vector<T> &v)
{
    std::shuffle(std::begin(v), std::end(v), rng);
}

int main()
{
    std::vector<int> v{0, 1, 2, 3, 4, 5, 56, 6, 7, 7, 5, 4, 3};
    shuffle_vector(v);
    for (const auto &i : v)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}
