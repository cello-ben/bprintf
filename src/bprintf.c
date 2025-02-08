/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <bprintf.h>
#include <blib.h>

#ifdef BPRINTF_DEBUG
    #include <stdarg.h>
	#include <stdio.h>
	#include <unistd.h>
#endif

#define SPACE_CODE 32
const LEDState SPACE_CHAR[CHAR_WIDTH * CHAR_HEIGHT] = {LED_OFF};

#define PERIOD_CODE 46
const LEDState PERIOD_CHAR[CHAR_WIDTH * CHAR_HEIGHT] = {
		LED_OFF, LED_OFF, LED_OFF,
		LED_OFF, LED_OFF, LED_OFF,
		LED_OFF, LED_OFF, LED_ON
	};

const LEDState NUMS[10][CHAR_WIDTH * CHAR_HEIGHT] = {
	{	//0
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_OFF, LED_ON,
		LED_OFF, LED_ON, LED_OFF
	},
	{	//1
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{	//2
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{	//3
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{	//4
		LED_ON, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{	//5
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{	//6
		LED_ON, LED_OFF, LED_OFF,
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{	//7
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_OFF, LED_ON,
		LED_OFF, LED_OFF, LED_ON
	},
	{	//8
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{	//9
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_OFF, LED_ON
	}
};

const LEDState ALPHA[26][CHAR_WIDTH * CHAR_HEIGHT] = {
	{	//A
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_ON
	},
	{	//B
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{	//C
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{	//D
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{	//E
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{	//F
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_OFF,
		LED_ON, LED_OFF, LED_OFF
	},
	{	//G
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{	//H
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_ON
	},
	{	//I
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{	//J
		LED_OFF, LED_OFF, LED_ON,
		LED_OFF, LED_OFF, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{	//K
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_ON, LED_OFF,
		LED_ON, LED_OFF, LED_ON
	},
	{	//L
		LED_ON, LED_OFF, LED_OFF,
		LED_ON, LED_OFF, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{	//M
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_ON
	},
	{	//N
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_ON
	},
	{	//O
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_OFF, LED_ON,
		LED_OFF, LED_ON, LED_OFF
	},
	{	//P
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_OFF, LED_OFF
	},
	{	//Q
		LED_ON, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_OFF,
		LED_OFF, LED_OFF, LED_ON
	},
	{	//R
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_ON
	},
	{	//S
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{	//T
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_ON, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{	//U
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{	//V
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_OFF, LED_ON,
		LED_OFF, LED_ON, LED_OFF
	},
	{	//W
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{	//X
		LED_ON, LED_OFF, LED_ON,
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_OFF, LED_ON
	},
	{	//Y
		LED_ON, LED_OFF, LED_ON,
		LED_OFF, LED_ON, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{	//Z
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_ON
	}
};

int _debug_printf(const char *fmt, ...) //TODO decide if I want to return BPrintfStatus from printing functions instead of regular integers.
{
    #ifdef BPRINTF_DEBUG
        va_list args;
        va_start(args, fmt);
        int vprintf_res = vprintf(fmt, args);
        va_end(args);
        return vprintf_res;
    #endif
    return 0;
}

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
		return BPRINTF_SUCCESS; //Placeholder
	#endif
	//Call on x times with pins we need to activate.
	//Sleep for 1 second.
	//Call off x times with pins we need to deactivate.
	//Return BPRINTF_BOARD_SEND_ERR for error.
	return BPRINTF_SUCCESS;
}

BPrintfStatus bputchar(char c)
{
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
        return send_to_board(NUMS[c-NUM_OFFSET]);
	}
	else if (c >= ALPHA_MIN && c <= ALPHA_MAX)
	{
        return send_to_board(ALPHA[c - ALPHA_OFFSET]);
	}
    return BPRINTF_INVALID_CHAR_ERR;
	
}

int bprintf(const char *fmt, ...)
{
	//Initial strategy:
	//Figure out a way to take in variadic arguments. For the time being, we'll assume all ints after the format string.
	char buffer[BPRINTF_BUF_LEN + 1];
	va_list args;
	va_start(args, fmt);

	//Parse format specifiers.
	bsize_t str_idx = 0;
	while (*fmt != '\0')
	{
		if (str_idx == BPRINTF_BUF_LEN)
		{
			buffer[BPRINTF_BUF_LEN] = '\0';
			break;
		}
		if (*fmt == '%')
		{
			char c;
			char *n;
			switch (*(fmt + 1))
			{
				case 'c':
					c = (char)va_arg(args, int);
					fmt++;
					buffer[str_idx++] = c;
					break;
				case 'd':
				case 'i':
					n = itos(va_arg(args, int));
					fmt++;
					while (*n != '\0' && str_idx < BPRINTF_BUF_LEN)
					{
						buffer[str_idx++] = *n;
						n++;
					}
					break;
				case 'l':
					_debug_printf("Time for a long.\n");
					c = *(fmt + 2);
					_debug_printf("Next char: %c\n", c);
					if (c == 'd' || c == 'i')
					{
						n = ltos(va_arg(args, long));
						_debug_printf("Long: %s\n", n);
						fmt += 2;
						while (*n != '\0' && str_idx < BPRINTF_BUF_LEN)
						{
							buffer[str_idx++] = *n;
							n++;
						}
					}
					break;
				case 's':
					n = va_arg(args, char*);
					fmt++;
					while (*n != '\0' && str_idx < BPRINTF_BUF_LEN)
					{
						buffer[str_idx++] = *n;
						n++;
					}
					break;
				default:
					//We don't support printing the '%' sign, so there's no point in putting it in the buffer.
					break;

			}
		}
		else
		{
			buffer[str_idx++] = *fmt;
		}
		fmt++;
	}
	buffer[str_idx] = '\0';
	for (bsize_t i = 0; i < str_idx; i++)
	{
		bputchar(buffer[i]);
		#ifdef BPRINTF_DEBUG
			usleep(SLEEP_USEC);
		#endif
	}
	return ++str_idx; //TODO figure out if this needs to be incremented or not.
}
