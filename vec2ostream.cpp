#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <variant>
#include <vector>

template <typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    if (v.size() == 0)
    {
        os << "[]";
        return os;
    }
    auto it{v.begin()};

    os << '[';
    size_t vcounter{0};
    while (it != v.end())
    {
        vcounter++;
        os << *it;
        os << ", ";
        it++;
        if (vcounter == v.size() - 1)
        {
            break;
        }
    }
    os << *it;
    os << ']';

    return os;
}

template <typename T, typename U> std::ostream &operator<<(std::ostream &os, const std::vector<std::pair<T, U>> &v)

{
    if (v.size() == 0)
    {
        os << "[]";
        return os;
    }
    auto it{v.begin()};

    os << '[';
    size_t vcounter{0};
    while (it != v.end())
    {
        vcounter++;
        os << '(';
        os << it->first;
        os << ", ";
        os << it->second;
        os << "),";
        it++;
        if (vcounter == v.size() - 1)
        {
            break;
        }
    }
    os << '(';
    os << it->first;
    os << ", ";
    os << it->second;
    os << ")";
    os << ']';

    return os;
}

template <typename T> std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v)

{
    if (v.size() == 0)
    {
        os << "[]";
        return os;
    }
    auto it{v.begin()};

    os << '[';
    size_t vcounter{0};
    while (it != v.end())
    {
        vcounter++;
        os << *it;
        os << ',';
        it++;

        if (vcounter == v.size() - 1)
        {
            break;
        }
    }
    os << *it;
    os << ']';

    return os;
}

int main()
{

    std::vector<int> vec1{1, 2, 3, 34, 45, 5, 6, 76, 78};
    std::vector<float> vec2{1.4, 2, 3.33, 3.4, 4.5, 5, 6, 76, 78};
    std::vector<std::pair<std::string, float>> vec3{{"a", 1.4}, {"b", 2}, {"c", 3.33}};
    std::vector<std::vector<std::pair<std::string, float>>> vec4{{{"a", 1.4}, {"b", 2}, {"c", 3.33}},
                                                                 {{"a", 1.4}, {"b", 2}, {"c", 3.33}}};
    std::cout << vec1 << std::endl;
    std::cout << vec2 << std::endl;
    std::cout << vec3 << std::endl;
    std::cout << vec4 << std::endl;
    return 0;
}
