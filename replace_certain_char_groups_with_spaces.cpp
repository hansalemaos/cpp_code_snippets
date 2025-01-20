#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

static constexpr std::array<uint8_t, 256> array_ascii_replace_non_alphanumeric{
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  32,  32,  32,  32,  32,  32,  32,  65,
    66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,  81,  82,  83,  84,  85,  86,  87,
    88,  89,  90,  32,  32,  32,  32,  32,  32,  97,  98,  99,  100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
    110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32};

static constexpr std::array<uint8_t, 256> array_ascii_replace_non_printable{
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,
    44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63,  64,  65,
    66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,  81,  82,  83,  84,  85,  86,  87,
    88,  89,  90,  91,  92,  93,  94,  95,  96,  97,  98,  99,  100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
    110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32};
static constexpr std::array<uint8_t, 256> array_ascii_replace_non_numeric{
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 0-15
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 16-31
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 32-47
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57,                         // 48-57 (digits '0'-'9')
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 58-73
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 74-89
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 90-105
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 106-121
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 122-137
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 138-153
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 154-169
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 170-185
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 186-201
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 202-217
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 218-233
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32  // 234-255
};
static constexpr std::array<uint8_t, 256> array_ascii_replace_non_numeric_float{
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 0-15
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 16-31
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 46, 32, // 32-47
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57,                         // 48-57 (digits '0'-'9')
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 58-73
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 74-89
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 90-105
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 106-121
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 122-137
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 138-153
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 154-169
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 170-185
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 186-201
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 202-217
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 218-233
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32  // 234-255
};

static constexpr std::array<uint8_t, 256> array_ascii_replace_non_numeric_float_with_comma{
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 0-15
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 16-31
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 44, 32, 46, 32, // 32-47
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57,                         // 48-57 (digits '0'-'9')
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 58-73
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 74-89
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 90-105
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 106-121
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 122-137
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 138-153
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 154-169
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 170-185
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 186-201
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 202-217
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 218-233
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32  // 234-255
};

static std::string replace_fu(const std::string_view s, int op)
{
    std::string outv;
    outv.reserve(s.size());
    auto siterstart{s.begin()};
    auto siterend{s.end()};
    if (op == 0)
    {
        while (siterstart != siterend)
        {
            outv += (array_ascii_replace_non_alphanumeric[*siterstart++]);
        }
    }
    else if (op == 1)
    {
        while (siterstart != siterend)
        {
            outv += (array_ascii_replace_non_printable[*siterstart++]);
        }
    }
    else if (op == 2)
    {
        while (siterstart != siterend)
        {
            outv += (array_ascii_replace_non_numeric[*siterstart++]);
        }
    }
    else if (op == 3)
    {
        while (siterstart != siterend)
        {
            outv += (array_ascii_replace_non_numeric_float[*siterstart++]);
        }
    }
    else if (op == 4)
    {
        while (siterstart != siterend)
        {
            outv += (array_ascii_replace_non_numeric_float_with_comma[*siterstart++]);
        }
    }
    return outv;
}

std::string replace_non_alphanumeric_with_spaces(std::string_view _sv)
{
    return replace_fu(_sv, 0);
}
std::string replace_non_printable_with_spaces(std::string_view _sv)
{
    return replace_fu(_sv, 1);
}
std::string replace_non_decimal_with_spaces(std::string_view _sv)
{
    return replace_fu(_sv, 2);
}
std::string replace_non_float_with_spaces(std::string_view _sv)
{
    return replace_fu(_sv, 3);
}
std::string replace_non_float_with_spaces_and_comma(std::string_view _sv)
{
    return replace_fu(_sv, 4);
}

int main()
{

    std::string test1{"0x1234!!!2"};
    std::string test2{"0x12\4\5xx\34"};
    std::string test3{"0x12hf234"};
    std::string test4{"0x1f234"};
    std::string test5{"123.4"};
    std::string test6{"0X1234"};
    std::string test7{"0x1  234"};
    std::string test8{"0X1234"};

    std::cout << replace_non_alphanumeric_with_spaces(test1) << std::endl;
    std::cout << replace_non_alphanumeric_with_spaces(test2) << std::endl;
    std::cout << replace_non_alphanumeric_with_spaces(test3) << std::endl;
    std::cout << replace_non_alphanumeric_with_spaces(test4) << std::endl;
    std::cout << replace_non_alphanumeric_with_spaces(test5) << std::endl;
    std::cout << replace_non_alphanumeric_with_spaces(test6) << std::endl;
    std::cout << replace_non_alphanumeric_with_spaces(test7) << std::endl;
    std::cout << replace_non_alphanumeric_with_spaces(test8) << std::endl;

    std::cout << replace_non_printable_with_spaces(test1) << std::endl;
    std::cout << replace_non_printable_with_spaces(test2) << std::endl;
    std::cout << replace_non_printable_with_spaces(test3) << std::endl;
    std::cout << replace_non_printable_with_spaces(test4) << std::endl;
    std::cout << replace_non_printable_with_spaces(test5) << std::endl;
    std::cout << replace_non_printable_with_spaces(test6) << std::endl;
    std::cout << replace_non_printable_with_spaces(test7) << std::endl;
    std::cout << replace_non_printable_with_spaces(test8) << std::endl;

    std::cout << replace_non_decimal_with_spaces(test1) << std::endl;
    std::cout << replace_non_decimal_with_spaces(test2) << std::endl;
    std::cout << replace_non_decimal_with_spaces(test3) << std::endl;
    std::cout << replace_non_decimal_with_spaces(test4) << std::endl;
    std::cout << replace_non_decimal_with_spaces(test5) << std::endl;
    std::cout << replace_non_decimal_with_spaces(test6) << std::endl;
    std::cout << replace_non_decimal_with_spaces(test7) << std::endl;
    std::cout << replace_non_decimal_with_spaces(test8) << std::endl;

    std::cout << replace_non_float_with_spaces(test1) << std::endl;
    std::cout << replace_non_float_with_spaces(test2) << std::endl;
    std::cout << replace_non_float_with_spaces(test3) << std::endl;
    std::cout << replace_non_float_with_spaces(test4) << std::endl;
    std::cout << replace_non_float_with_spaces(test5) << std::endl;
    std::cout << replace_non_float_with_spaces(test6) << std::endl;
    std::cout << replace_non_float_with_spaces(test7) << std::endl;
    std::cout << replace_non_float_with_spaces(test8) << std::endl;

    return 0;
}
