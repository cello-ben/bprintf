/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdarg.h>

#include <ascii.h>
#include <bprintf.h>
#include <blib.h>

#ifdef BPRINTF_DEBUG
	#include <stdio.h>
#endif

const int LED_MAP[CHAR_WIDTH * CHAR_HEIGHT] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

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

int _debug_print_char(const LEDState *grid) //TODO decide whether or not to keep.
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

BPrintfStatus flush(void)
{
	return BPRINTF_SUCCESS; //Placeholder
}

BPrintfStatus send_to_board(const LEDState *leds)
{
	#ifdef BPRINTF_DEBUG
		return _debug_print_char(leds);
	#else
		//for (int i = 0; i < CHAR_WIDTH * CHAR_HEIGHT; i++)
		// {
		// 	gpio_put(LED_MAP[i], leds[i]);
		// }
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
	return send_to_board(ASCII_MAP[(bsize_t)c]) == BPRINTF_SUCCESS ? BPRINTF_SUCCESS : BPRINTF_INVALID_CHAR_ERR; 	
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
		if (*fmt == '%') //TODO figure out why longs, etc. aren't making their way into s.
		{
			char c;
			char *s;
			switch (*(fmt + 1)) //Massive, hideous switch statement. I'm no happier about it than you are. However, this seems to be the most straightforward way to deal with the logic since we don't have a heap (very much open to being enlightened otherwise).
			{
				case 'c':
					c = (char)va_arg(args, int);
					buffer[str_idx++] = c;
					fmt++;
					break;
				case 'd':
				case 'i':
					s = itos(va_arg(args, int));
					goto copy_to_buffer;
					break;
				case 'l':
					c = *(fmt + 2);
					if (c == 'd' || c == 'i')
					{
						s = ltos(va_arg(args, long));
						fmt++;
					}
					else if (c == 'u')
					{
						s = ultos(va_arg(args, unsigned long));
						fmt++;
					}
					else if (c == 'l')
					{
						c = *(fmt + 3);
						fmt++;
						if (c == 'd' || c == 'i')
						{
							s = lltos(va_arg(args, long long));
							fmt++;
						}
						else if (c == 'u')
						{
							s = ulltos(va_arg(args, unsigned long long));
							fmt++;
						}
						else
						{
							s = "";
						}
					}
					else
					{
						s = "";
					}
					goto copy_to_buffer;
				case 's':
					s = va_arg(args, char*);
					goto copy_to_buffer;
					break; //TODO check to make sure break is not needed after a goto statement.
				case 'R':
					//Why not include Roman numeral to decimal string conversion? ;)
					s = rtods(va_arg(args, char*));
					goto copy_to_buffer;
				copy_to_buffer:
					fmt++;
					while (*s != '\0' && str_idx < BPRINTF_BUF_LEN)
					{
						buffer[str_idx++] = *s;
						s++;
					}
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
	_debug_printf("%s\n", buffer);
	for (bsize_t i = 0; i < str_idx; i++)
	{
		#ifndef BPRINTF_SKIP_PUTCHAR
			if (bputchar(buffer[i]) == BPRINTF_PUTCHAR_ERR)
			{
				return -1;
			}
			//SLEEP
			if (bputchar(' ') == BPRINTF_PUTCHAR_ERR)
			{
				return -1;
			}
		#endif
	}
	return ++str_idx; //TODO figure out if this needs to be incremented or not.
}
