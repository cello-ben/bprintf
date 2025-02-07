/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <bprintf.h>
#ifdef BPRINTF_DEBUG
	#include <stdio.h>
#endif

int _debug_print_char(const LEDState *grid)
{
	int putchar_res = 0;
	#ifdef BPRINTF_DEBUG
		for (int i = 0; i <= (CHAR_WIDTH * CHAR_HEIGHT); i++)
		{
			if (grid[i] == LED_ON)
			{
				putchar_res = putchar('*');
			}
			else
			{
				putchar_res = putchar(' ');
			}
			if (putchar_res == EOF)
			{
				return putchar_res;
			}
			if (i % 3 == 0)
			{
				putchar_res = putchar('\n');
				if (putchar_res == EOF)
				{
					return putchar_res;
				}
			}
		}
		return (int)putchar_res;
	#endif
	return 0;
}

int off(int led)
{
	return 0;
}

int on(int led)
{
	return 0;	
}

int send_to_board(int *leds)
{
	//Call on x times with pins we need to activate.
	//Sleep for 1 second.
	//Call off x times with pins we need to deactivate.
	return 0;
}

int bputchar(char c)
{
	return 0;
}

int main(void)
{
	const LEDState *B = NUMS['1' - NUM_OFFSET];
	_debug_print_char(B);
	return 0;
}
