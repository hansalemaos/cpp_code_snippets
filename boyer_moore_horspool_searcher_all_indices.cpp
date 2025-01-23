#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

std::vector<size_t> boyer_moore_horspool_searcher_all(const std::string_view in, const std::string_view needle,
                                                      int approx_size = 1024)
{
    std::vector<size_t> results;
    results.reserve(approx_size);
    auto in_end = in.end();
    size_t offset = 0;
    for (;;)
    {
        auto it = std::search(in.begin() + offset, in.end(),
                              std::boyer_moore_horspool_searcher(needle.begin(), needle.end()));
        if (it != in.end())
        {
            results.emplace_back(it - in.begin());
            offset = it - in.begin() + 1;
        }
        else
        {
            break;
        }
    }
    return results;
}
int main()
{
    std::string teststring{"hello world hello worldhello world hello worldhello world hello worldhello world hello "
                           "worldhello world hello worldhello world hello worldhello world hello world"};
    auto vec1{boyer_moore_horspool_searcher_all(teststring, "hello", 20)};
    for (auto i : vec1)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
