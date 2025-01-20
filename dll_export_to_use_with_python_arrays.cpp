#include <iostream>
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif
// zig c++ -shared -std=c++2a -O3 -g0 dlltest.cpp -o mytest.dll
extern "C" DLL_EXPORT void add_vecs_int(size_t array1, size_t size_array1, size_t array2, size_t size_array2)
{
    if (size_array1 != size_array2)
    {
        throw std::runtime_error("Size mismatch");
    }
    int64_t *ptr1{(int64_t *)array1};
    int64_t *ptr2{(int64_t *)array2};
    for (size_t i{}; i < size_array1; ++i)
    {
        ptr1[i] += ptr2[i];
    }
}
