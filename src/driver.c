/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <bprintf.h>

#include <blib.h>
#include <bstring.h>

int main(void)
{
	_debug_printf("%s\n", itos(-47));
	// int putchar_res;

	//Check special characters (just space and period for now)
	// putchar_res = bputchar(' ');
	// if (putchar_res > 0)
	// {
	// 	return BPRINTF_PUTCHAR_ERR;
	// }

	// putchar_res = bputchar('.');
	// if (putchar_res > 0)
	// {
	// 	return BPRINTF_PUTCHAR_ERR;
	// }

	// // Test printing all nums
	// for (int i = NUM_MIN; i < NUM_MAX; i++)
	// {
	// 	putchar_res = bputchar(i);
	// 	if (putchar_res > 0)
	// 	{
	// 		return BPRINTF_PUTCHAR_ERR;
	// 	}
	// }

	// //Test printing all uppercase letters
	// for (int i = ALPHA_MIN; i < ALPHA_MAX; i++)
	// {
	// 	putchar_res = bputchar(i);
	// 	if (putchar_res > 0)
	// 	{
	// 		return BPRINTF_PUTCHAR_ERR;
	// 	}
	// }

	return 0;
}
