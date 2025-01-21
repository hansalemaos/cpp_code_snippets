#include <iostream>
static constexpr auto costexprabs(auto x)
{
    return x < 0 ? -x : x;
}

int main()
{
    std::cout << costexprabs(-1) << std::endl;
    return 0;
}
