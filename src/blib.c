/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <bprintf.h>

#include <blib.h>
#include <bstring.h>

char *itos(int n) //TODO check for overflows, etc.
{
	BBool negative = n < 0;
	char tmp[INT_MAX_DIGITS_LEN + 2]; //Extra 2 chars for negative and null terminator.
	int abs_n = ABS(n);
	bsize_t idx = 0;
	while (abs_n > 0)
	{
		tmp[idx++] = (abs_n % 10) + NUM_OFFSET;
		abs_n /= 10;
	}
	static char res[INT_MAX_DIGITS_LEN + 2]; //Workaround for no heap.
	if (negative == BTRUE)
	{
		res[0] = '-';
	}
	const bsize_t len = idx + (int)negative;
	res[idx--] = '\0'; //TODO figure out for sure if we need this.
	for (bsize_t i = (int)negative; i < len; i++)
	{
		res[i] = tmp[idx--];
	}
	return res;
}

char *rtods(const char *s) //TODO add long support when bug(s) fixed.
{
	int map[] = {
		['C'] = 100,
		['D'] = 500,
		['I'] = 1,
		['L'] = 50,
		['M'] = 1000,
		['V'] = 5,
		['X'] = 10
	};
	// int map[89] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    //             0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    //             0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    //             0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    //             0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    //             0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    //             0, 0, 0, 0, 0, 0, 0, 100, 500, 0, //C, D
    //             0, 0, 0, 1, 0, 0, 50, 1000, 0, 0, //I, L, M
    //             0, 0, 0, 0, 0, 0, 5, 0, 10}; //V, X

    bsize_t len = bstrlen(s);
    int num = 0, i = len - 1;

    while (i >= 0)
    {
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

    return itos(num);
}

char *ltos(long n) //TODO check fix bugs manifest when calling from rtods.
{
	BBool negative = n < 0;
	char tmp[LONG_MAX_DIGITS_LEN + 2]; //Extra 2 chars for negative and null terminator.
	long abs_n = ABS(n);
	bsize_t idx = 0;
	while (abs_n > 0)
	{
		tmp[idx++] = (abs_n % 10) + NUM_OFFSET;
		abs_n /= 10;
	}
	static char res[LONG_MAX_DIGITS_LEN + 2]; //Workaround for no heap.
	if (negative == BTRUE)
	{
		res[0] = '-';
	}
	const bsize_t len = idx + (int)negative;
	res[idx--] = '\0'; //TODO figure out for sure if we need this.
	for (bsize_t i = (int)negative; i < len; i++)
	{
		res[i] = tmp[idx--];
	}
	return res;
}

char *ultos(unsigned long n)
{
	char tmp[ULONG_MAX_DIGITS_LEN + 2]; //Extra 2 chars for negative and null terminator.
	long abs_n = ABS(n);
	bsize_t idx = 0;
	while (abs_n > 0)
	{
		tmp[idx++] = (abs_n % 10) + NUM_OFFSET;
		abs_n /= 10;
	}
	static char res[ULONG_MAX_DIGITS_LEN + 2]; //Workaround for no heap.
	const bsize_t len = idx;
	res[idx--] = '\0'; //TODO figure out for sure if we need this.
	for (bsize_t i = 0; i < len; i++)
	{
		res[i] = tmp[idx--];
	}
	return res;
}

char *lltos(long long n)
{
	BBool negative = n < 0;
	char tmp[LONG_LONG_MAX_DIGITS_LEN + 2]; //Extra 2 chars for negative and null terminator.
	long abs_n = ABS(n);
	bsize_t idx = 0;
	while (abs_n > 0)
	{
		tmp[idx++] = (abs_n % 10) + NUM_OFFSET;
		abs_n /= 10;
	}
	static char res[LONG_LONG_MAX_DIGITS_LEN + 2]; //Workaround for no heap.
	if (negative == BTRUE)
	{
		res[0] = '-';
	}
	const bsize_t len = idx + (int)negative;
	res[idx--] = '\0'; //TODO figure out for sure if we need this.
	for (bsize_t i = (int)negative; i < len; i++)
	{
		res[i] = tmp[idx--];
	}
	return res;
}

char *ulltos(unsigned long long n)
{
	char tmp[ULONG_LONG_MAX_DIGITS_LEN + 2]; //Extra 2 chars for negative and null terminator.
	bsize_t idx = 0;
	while (n > 0)
	{
		tmp[idx++] = (n % 10) + NUM_OFFSET;
		n /= 10;
	}
	static char res[ULONG_LONG_MAX_DIGITS_LEN + 2]; //Workaround for no heap.
	const bsize_t len = idx;
	res[idx--] = '\0'; //TODO figure out for sure if we need this.
	for (bsize_t i = 0; i < len; i++)
	{
		res[i] = tmp[idx--];
	}
	return res;
}
