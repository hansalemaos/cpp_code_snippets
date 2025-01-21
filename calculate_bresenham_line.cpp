#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> static calculate_bresenham_line(int x1, int y1, int x2, int y2)
{
    int dx = ::abs(x2 - x1);
    int dy = ::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int e2 = 0;
    std::vector<std::pair<int, int>> points;
    points.reserve((std::max(dx, dy) + 1) * 4);

    for (;;)
    {
        points.emplace_back(std::make_pair(x1, y1));

        if (x1 == x2 && y1 == y2)
        {
            break;
        }

        e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
    return points;
}

int main(int argc, char **argv)
{
    auto brasvec{calculate_bresenham_line(0, 0, 10, 10)};
    for (const auto &point : brasvec)
    {
        std::cout << point.first << "," << point.second << std::endl;
    }
    return 0;
}
