#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>
/*
Based on https://github.com/imageworks/pystring
Copyright (c) 2008-present Contributors to the Pystring project.
All Rights Reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.*/

#define MAX_32BIT_INT 2147483647

#define ADJUST_INDICES(start, end, len)                                                                                \
    if (end > len)                                                                                                     \
        end = len;                                                                                                     \
    else if (end < 0)                                                                                                  \
    {                                                                                                                  \
        end += len;                                                                                                    \
        if (end < 0)                                                                                                   \
            end = 0;                                                                                                   \
    }                                                                                                                  \
    if (start < 0)                                                                                                     \
    {                                                                                                                  \
        start += len;                                                                                                  \
        if (start < 0)                                                                                                 \
            start = 0;                                                                                                 \
    }

static int constexpr find(const std::string_view str, const std::string_view sub, int start = 0,
                          int end = MAX_32BIT_INT)
{
    ADJUST_INDICES(start, end, (int)str.size());
    std::string::size_type result{str.substr(0, end).find(sub, start)};
    if (result == std::string::npos || (result + sub.size() > (std::string::size_type)end))
    {
        return -1;
    }
    return (int)result;
}

static constexpr std::array<std::pair<std::string_view, std::string_view>, 63> accent_map{
    std::make_pair("�", "A"), std::make_pair("�", "A"), std::make_pair("�", "A"), std::make_pair("�", "A"),
    std::make_pair("�", "A"), std::make_pair("�", "A"), std::make_pair("�", "E"), std::make_pair("�", "C"),
    std::make_pair("�", "E"), std::make_pair("�", "E"), std::make_pair("�", "E"), std::make_pair("�", "E"),
    std::make_pair("�", "I"), std::make_pair("�", "I"), std::make_pair("�", "I"), std::make_pair("�", "I"),
    std::make_pair("�", "D"), std::make_pair("�", "N"), std::make_pair("�", "O"), std::make_pair("�", "O"),
    std::make_pair("�", "O"), std::make_pair("�", "O"), std::make_pair("�", "O"), std::make_pair("�", "x"),
    std::make_pair("�", "0"), std::make_pair("�", "U"), std::make_pair("�", "U"), std::make_pair("�", "U"),
    std::make_pair("�", "U"), std::make_pair("�", "Y"), std::make_pair("�", "P"), std::make_pair("�", "a"),
    std::make_pair("�", "a"), std::make_pair("�", "a"), std::make_pair("�", "a"), std::make_pair("�", "a"),
    std::make_pair("�", "a"), std::make_pair("�", "e"), std::make_pair("�", "c"), std::make_pair("�", "e"),
    std::make_pair("�", "e"), std::make_pair("�", "e"), std::make_pair("�", "e"), std::make_pair("�", "i"),
    std::make_pair("�", "i"), std::make_pair("�", "i"), std::make_pair("�", "i"), std::make_pair("�", "O"),
    std::make_pair("�", "n"), std::make_pair("�", "o"), std::make_pair("�", "o"), std::make_pair("�", "o"),
    std::make_pair("�", "o"), std::make_pair("�", "o"), std::make_pair("�", "/"), std::make_pair("�", "0"),
    std::make_pair("�", "u"), std::make_pair("�", "u"), std::make_pair("�", "u"), std::make_pair("�", "u"),
    std::make_pair("�", "y"), std::make_pair("�", "p"), std::make_pair("�", "y"),
};

static constexpr std::string_view all_accents_as_string{
    "���������������������������������������������������������������"};

static void constexpr remove_accents_from_string(std::string &s, bool do_precheck = true, int count = MAX_32BIT_INT)
{
    if (s.empty())
    {
        return;
    }
    if (do_precheck)
    {
        std::size_t found = s.find_first_of(all_accents_as_string);
        if (found == std::string::npos)
        {
            return;
        }
    }
    std::string::size_type oldlen{1};
    std::string::size_type newlen{1};
    for (size_t j{}; j < accent_map.size(); j++)
    {
        int sofar{};
        int cursor{};
        cursor = find(s, accent_map[j].first, cursor);
        while (cursor != -1 && cursor <= (int)s.size())
        {
            if (count > -1 && sofar >= count)
            {
                break;
            }
            s.replace(cursor, oldlen, accent_map[j].second);
            cursor += (int)newlen;
            if (oldlen != 0)
            {
                cursor = find(s, accent_map[j].first, cursor);
            }
            else
            {
                ++cursor;
            }
            ++sofar;
        }
    }
}

int main()
{
    std::string mystring{"Hello Wo����������������������rld!Hello World!Hello World!He�����������������llo World!"};

    std::cout << mystring << std::endl;
    remove_accents_from_string(mystring, true, 2);
    std::cout << mystring << std::endl;

    return 0;
}
