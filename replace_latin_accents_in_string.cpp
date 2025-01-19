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
    std::make_pair("À", "A"), std::make_pair("Á", "A"), std::make_pair("Â", "A"), std::make_pair("Ã", "A"),
    std::make_pair("Ä", "A"), std::make_pair("Å", "A"), std::make_pair("Æ", "E"), std::make_pair("Ç", "C"),
    std::make_pair("È", "E"), std::make_pair("É", "E"), std::make_pair("Ê", "E"), std::make_pair("Ë", "E"),
    std::make_pair("Ì", "I"), std::make_pair("Í", "I"), std::make_pair("Î", "I"), std::make_pair("Ï", "I"),
    std::make_pair("Ğ", "D"), std::make_pair("Ñ", "N"), std::make_pair("Ò", "O"), std::make_pair("Ó", "O"),
    std::make_pair("Ô", "O"), std::make_pair("Õ", "O"), std::make_pair("Ö", "O"), std::make_pair("×", "x"),
    std::make_pair("Ø", "0"), std::make_pair("Ù", "U"), std::make_pair("Ú", "U"), std::make_pair("Û", "U"),
    std::make_pair("Ü", "U"), std::make_pair("İ", "Y"), std::make_pair("Ş", "P"), std::make_pair("à", "a"),
    std::make_pair("á", "a"), std::make_pair("â", "a"), std::make_pair("ã", "a"), std::make_pair("ä", "a"),
    std::make_pair("å", "a"), std::make_pair("æ", "e"), std::make_pair("ç", "c"), std::make_pair("è", "e"),
    std::make_pair("é", "e"), std::make_pair("ê", "e"), std::make_pair("ë", "e"), std::make_pair("ì", "i"),
    std::make_pair("í", "i"), std::make_pair("î", "i"), std::make_pair("ï", "i"), std::make_pair("ğ", "O"),
    std::make_pair("ñ", "n"), std::make_pair("ò", "o"), std::make_pair("ó", "o"), std::make_pair("ô", "o"),
    std::make_pair("õ", "o"), std::make_pair("ö", "o"), std::make_pair("÷", "/"), std::make_pair("ø", "0"),
    std::make_pair("ù", "u"), std::make_pair("ú", "u"), std::make_pair("û", "u"), std::make_pair("ü", "u"),
    std::make_pair("ı", "y"), std::make_pair("ş", "p"), std::make_pair("ÿ", "y"),
};

static constexpr std::string_view all_accents_as_string{
    "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞàáâãäåæçèéêëìíîïğñòóôõö÷øùúûüışÿ"};

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
    std::string mystring{"Hello Woçèéêëìíîïğñòóôõö÷øùúûürld!Hello World!Hello World!HeÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙllo World!"};

    std::cout << mystring << std::endl;
    remove_accents_from_string(mystring, true, 2);
    std::cout << mystring << std::endl;

    return 0;
}
