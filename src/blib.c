/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <bprintf.h>

#include <blib.h>
#include <bstring.h>

char *itos(int n)
{
	BBool negative = n < 0;
	char tmp[11];
	int abs_n = ABS(n);
	bsize_t idx = 0;
	while (abs_n)
	{
		tmp[idx++] = (abs_n % 10) + NUM_OFFSET;
		abs_n /= 10;
	}
	static char res[11]; //Workaround for no heap.
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
