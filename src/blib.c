/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "bprintf.h"
#include "blib.h"
#include "bstring.h"

char *stringifyn(long long n, BBool negative)
{
    if (n == 0)
    {
        return "0";
    }
    if (negative == BTRUE)
    {
        n = -n;
    }
    char tmp[LONG_LONG_MAX_DIGITS_LEN + 2];

    bsize_t idx = 0;
    while (n)
    {
        tmp[idx++] = (n % 10) + NUM_OFFSET;
        n /= 10;
    }

    static char res[LONG_LONG_MAX_DIGITS_LEN + 2];
    if (negative == BTRUE)
    {
        res[0] = '-';
    }
    const bsize_t len = idx + (bsize_t)negative;
    res[idx--] = '\0';
    for (bsize_t i = (bsize_t)negative; i < len; i++)
    {
        res[i] = tmp[idx--];
    }
    return res;
}

char *ulltos(unsigned long long n) //We can use our general purpose stringifyn function for most use cases, but an unsigned long long can't be passed into it.
{
    if (n == 0)
    {
        return "0";
    }
    char tmp[ULONG_LONG_MAX_DIGITS_LEN + 1]; //Extra char for null terminator.
    bsize_t idx = 0;
    while (n > 0)
    {
        tmp[idx++] = (n % 10) + NUM_OFFSET;
    }
    static char res[ULONG_LONG_MAX_DIGITS_LEN + 1];
    const bsize_t len = idx;
    res[idx--] = '\0';
    for (bsize_t i = 0; i < len; i++)
    {
        res[i] = tmp[idx--];
    }
    return res;
}

char *rtods(const char *s)
{
    int map[ROMAN_MAP_LEN] = {
        ['C'] = 100,
        ['D'] = 500,
        ['I'] = 1,
        ['L'] = 50,
        ['M'] = 1000,
        ['V'] = 5,
        ['X'] = 10
    };

    int i = (int)bstrlen(s) - 1;
    int num = 0;

    if (!*s)
    {
        return ""; //Responding to an empty string with an empty string.
    }

    while (i >= 0)
    {
        if (s[i] < 0 || s[i] > ROMAN_MAP_LEN || !map[(bsize_t)s[i]])
        {
            return "<INVALID ROMAN NUMERAL>";
        }
        int curr = map[(bsize_t)s[i]];
        if (i != 0)
        {
            int prev = map[(bsize_t)s[i - 1]];
            if (curr > prev)
            {
                num -= prev;
                i--;
            }
        }
        num += curr;
        i--;
    }
    return stringifyn(num, BFALSE); //Only positive, we aren't doing negative Roman numerals.
}
