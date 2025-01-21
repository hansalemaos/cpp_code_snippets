#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

using vec_pair = std::vector<std::pair<int64_t, int64_t>>;
static constexpr float PI = 3.14159265358979323846;

static void _get_circle_coordinates(std::vector<std::pair<int64_t, int64_t>> &positions, int64_t x, int64_t y,
                                    int64_t r, float step_size = 0.005)
{

    float a{(float)y};
    float b{(float)x};
    float t{0};
    float ra{(float)r};
    int64_t last1{0};
    int64_t last2{0};
    int64_t next1{0};
    int64_t next2{0};

    while (t < 2 * PI)
    {
        next1 = (int64_t)(ra * ::cos(t) + a);
        next2 = (int64_t)(ra * ::sin(t) + b);
        if ((positions.size() > 0) && (last1 == next1) && (last2 == next2))
        {
            t += step_size;
            continue;
        }
        positions.emplace_back(std::make_pair(next1, next2));
        last1 = next1;
        last2 = next2;

        t += step_size;
    }
}
static std::vector<std::pair<int64_t, int64_t>> get_circle_coordinates(int64_t x, int64_t y, int64_t r,
                                                                       float step_size = 0.005)
{
    std::vector<std::pair<int64_t, int64_t>> positions;
    positions.reserve((r + 1) * (r + 1));
    _get_circle_coordinates(positions, x, y, r, step_size);
    return positions;
}

int main()
{
    std::vector<std::pair<int64_t, int64_t>> v{get_circle_coordinates(10, 20, 5, 0.005)};

    for (const auto &i : v)
    {
        std::cout << '(' << i.first << ", " << i.second << "), ";
    }
    std::cout << '\n';
}
