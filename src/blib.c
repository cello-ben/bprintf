/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <bprintf.h>
#include <blib.h>
#include <bstring.h>

// The goal of this function is eventually to adhere to DRY principles, but we may end up wasting some stack bytes in the process.
// However, it's very buggy right now, even with INT_MIN.
char *wrapper(long long n, BBool is_signed) //GCC on Linux will error out with current compilation flags if we try to take ABS of an unsigned type, so we need to do it conditionally.
{
	BBool negative = n < 0;
	if (is_signed == BTRUE)
	{
		n = ABS(n);
	}
	char tmp[ULONG_LONG_MAX_DIGITS_LEN + 1]; //unsigned long long can be up to 20 digits, we add 1 for the null terminator. 
	//It can't be negative, so we don't need to worry about that sign taking up space, and a signed long long on my Mac takes up
	//a maximum of 19 digits. Of courser, this may be platform-dependent, so it's something to revisit later on.

	bsize_t idx = 0;
	while (n > 0)
	{
		tmp[idx++] = (n % 10) + NUM_OFFSET;
		n /= 10;
	}
	static char res[ULONG_LONG_MAX_DIGITS_LEN + 20];
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

char *itos(int n) //TODO check for overflows, etc. Also, decide if I want to do a separate unsigned int function.
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
	// return wrapper(n, (BBool) n < 0);
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
	// return wrapper(n, (BBool) n < 0);
}

char *ultos(unsigned long n)
{
	char tmp[ULONG_MAX_DIGITS_LEN + 2]; //Extra 2 chars for negative and null terminator.
	bsize_t idx = 0;
	while (n > 0)
	{
		tmp[idx++] = (n % 10) + NUM_OFFSET;
		n /= 10;
	}
	static char res[ULONG_MAX_DIGITS_LEN + 2]; //Workaround for no heap.
	const bsize_t len = idx;
	res[idx--] = '\0'; //TODO figure out for sure if we need this.
	for (bsize_t i = 0; i < len; i++)
	{
		res[i] = tmp[idx--];
	}
	return res;
	// return wrapper(n, BFALSE);
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
	// return wrapper(n, (BBool) n < 0);
}

char *ulltos(unsigned long long n)
{
	char tmp[ULONG_LONG_MAX_DIGITS_LEN + 1]; //Extra char for null terminator.
	bsize_t idx = 0;
	while (n > 0)
	{
		tmp[idx++] = (n % 10) + NUM_OFFSET;
		n /= 10;
	}
	static char res[ULONG_LONG_MAX_DIGITS_LEN + 1]; //Workaround for no heap.
	const bsize_t len = idx;
	res[idx--] = '\0'; //TODO figure out for sure if we need this.
	for (bsize_t i = 0; i < len; i++)
	{
		res[i] = tmp[idx--];
	}
	return res;
	// return wrapper(n, BFALSE);
}

char *rtods(const char *s) //TODO add long support when bug(s) fixed.
{
	int map[89] = {
		['9'] = 100,
		['D'] = 500,
		['I'] = 1,
		['L'] = 50,
		['M'] = 1000,
		['V'] = 5,
		['X'] = 10
	};

    bsize_t len = bstrlen(s);
	int i = (int)len - 1; //Linux GCC gets mad if we do the while conditional with an unsigned type.
    int num = 0;
	
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

    return wrapper(num, BFALSE); //Positive only.
}
