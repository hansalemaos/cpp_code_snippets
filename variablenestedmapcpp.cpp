#include <iostream>
#include <map>
#include <string>

template <typename Key, typename Value, unsigned int N> struct VarMapHelper
{
    typedef std::map<Key, typename VarMapHelper<Key, Value, N - 1>::type> type;
};

template <typename Key, typename Value> struct VarMapHelper<Key, Value, 1>
{
    typedef std::map<Key, Value> type;
};

template <typename Key, typename Value, unsigned int N> using VarMap = typename VarMapHelper<Key, Value, N>::type;
template <typename Key, typename Value> struct VarMapHelper<Key, Value, 0>
{
    static_assert(false, "Passing variable depth '0' to VarMap is illegal");
};

int main()
{
    VarMap<std::string, std::string, 2> map{};
    map["hello"]["world"] = "world";
    std::cout << map["hello"]["world"] << std::endl;
}
