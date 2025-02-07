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
		for (int i = 0; i < CHAR_WIDTH; i++)
		{
			for (int j = 0; j < CHAR_HEIGHT; j++)
			{
				size_t idx = (i * CHAR_WIDTH) + j;
				putchar(grid[idx] == LED_ON ? '*' : ' ');
			}
			putchar('\n');
		}
		putchar('\n');
		return (int)putchar_res;
	#endif
	return 0;
}

BPrintfStatus off(int led)
{
	return 0;
}

BPrintfStatus on(int led)
{
	return 0;	
}

BPrintfStatus send_to_board(const LEDState *leds)
{
	#ifdef BPRINTF_DEBUG
		return _debug_print_char(leds);
	#else
		return BPRINTF_SUCCESS;
	#endif
	//Call on x times with pins we need to activate.
	//Sleep for 1 second.
	//Call off x times with pins we need to deactivate.
	//Return BPRINTF_BOARD_SEND_ERR for error.
	return BPRINTF_SUCCESS;
}

BPrintfStatus bputchar(char c)
{
	const LEDState *ptr;
	if (c == SPACE_CODE)
	{
		return send_to_board(SPACE_CHAR);
	}
	else if (c == PERIOD_CODE)
	{
		return send_to_board(PERIOD_CHAR);
	}
	else if (c >= NUM_MIN && c <= NUM_MAX)
	{
		ptr = NUMS[c - NUM_OFFSET];
		send_to_board(ptr);
	}
	else if (c >= ALPHA_MIN && c <= ALPHA_MAX)
	{
		ptr = ALPHA[c - ALPHA_OFFSET];
	}
	else
	{
		return BPRINTF_INVALID_CHAR_ERR;
	}
	return send_to_board(ptr);
}

int main(void)
{
	int putchar_res;

	//Check special characters (just space and period for now)
	putchar_res = bputchar(' ');
	if (putchar_res > 0)
	{
		return BPRINTF_PUTCHAR_ERR;
	}

	putchar_res = bputchar('.');
	if (putchar_res > 0)
	{
		return BPRINTF_PUTCHAR_ERR;
	}

	// Test printing all nums
	for (int i = NUM_MIN; i < NUM_MAX; i++)
	{
		putchar_res = bputchar(i);
		if (putchar_res > 0)
		{
			return BPRINTF_PUTCHAR_ERR;
		}
	}

	//Test printing all uppercase letters
	for (int i = ALPHA_MIN; i < ALPHA_MAX; i++)
	{
		putchar_res = bputchar(i);
		if (putchar_res > 0)
		{
			return BPRINTF_PUTCHAR_ERR;
		}
	}

	return 0;
}
