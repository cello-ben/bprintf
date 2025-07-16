/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdarg.h>

#include "bprintf.h"
#include "blib.h"

#ifdef BPRINTF_DEBUG
#include <stdio.h>
#else
#include "pico/stdlib.h"
#endif

const int LED_MAP[CHAR_WIDTH * CHAR_HEIGHT] = {20, 22, 19, 17, 18, 16, 21, 10, 12}; //This will likely need to be changed for other boards; it's based on arbitrary places where the LEDs happened to fit nicely on my breadboard.

static const LEDState ASCII_MAP[128][9] = {
	{LED_OFF}, //Placeholders
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},
	{LED_OFF},  //Space
	{LED_OFF},  //Exclamation point - not implemented.
	{
		LED_OFF, LED_ON, LED_ON, //Double quote
		LED_OFF, LED_ON, LED_ON,
		LED_OFF, LED_OFF, LED_OFF
	},
	{LED_OFF},  //Octothorpe - not implemented.
	{LED_OFF},  //Dollar sign - not implemented.
	{LED_OFF},  //Percent sign - not implemented.
	{LED_OFF},  //Ampersand - not implemented.
	{
		LED_OFF, LED_OFF, LED_ON, //Single quote/apostrophe
		LED_OFF, LED_OFF, LED_ON,
		LED_OFF, LED_OFF, LED_OFF
	},
	{
		LED_OFF, LED_ON, LED_OFF, //Left parenthesis
		LED_ON, LED_OFF, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_OFF, LED_ON, LED_OFF, //Right parenthesis
		LED_OFF, LED_OFF, LED_ON,
		LED_OFF, LED_ON, LED_OFF
	},
	{LED_OFF},  //Asterisk - not implemented.
	{
		LED_OFF, LED_ON, LED_OFF, //Plus sign
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_OFF, LED_OFF, LED_OFF, //Comma
		LED_OFF, LED_OFF, LED_ON,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_OFF, LED_OFF, LED_OFF, //Hyphen/negative sign
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_OFF, LED_OFF
	},
	{
		LED_OFF, LED_OFF, LED_OFF, //Period
		LED_OFF, LED_OFF, LED_OFF,
		LED_OFF, LED_OFF, LED_ON
	},
	{
		LED_OFF, LED_OFF, LED_ON, //Forward slash
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_OFF, LED_OFF
	},
	{
		LED_OFF, LED_ON, LED_OFF, //0
		LED_ON, LED_OFF, LED_ON,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_OFF, LED_ON, LED_OFF, //1
		LED_ON, LED_ON, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_ON, LED_ON, LED_OFF, //2
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //3
		LED_OFF, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_OFF, //4
		LED_ON, LED_ON, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_ON, LED_ON, LED_ON, //5
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_OFF, LED_OFF, //6
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //7
		LED_OFF, LED_OFF, LED_ON,
		LED_OFF, LED_OFF, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //8
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //9
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_OFF, LED_ON
	},
	{
		LED_OFF, LED_ON, LED_OFF, //Colon
		LED_OFF, LED_OFF, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{LED_OFF},  //Semicolon - not implemented.
	{LED_OFF},  //Less than sign - not implemented.
	{
		LED_ON, LED_ON, LED_ON, //Equals sign
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_OFF, LED_OFF
	},
	{LED_OFF},  //Greater than sign - not implemented.
	{LED_OFF},  //Question mark - not implemented.
	{LED_OFF},  //At sign - not implemented.
	{
		LED_OFF, LED_ON, LED_OFF, //A
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //B
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //C
		LED_ON, LED_OFF, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //D
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //E
		LED_ON, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //F
		LED_ON, LED_ON, LED_OFF,
		LED_ON, LED_OFF, LED_OFF
	},
	{
		LED_ON, LED_ON, LED_ON, //G
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_OFF, LED_ON, //H
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //I
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_OFF, LED_OFF, LED_ON, //J
		LED_OFF, LED_OFF, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_OFF, LED_ON, //K
		LED_ON, LED_ON, LED_OFF,
		LED_ON, LED_OFF, LED_ON
	},
	{
		LED_ON, LED_OFF, LED_OFF, //L
		LED_ON, LED_OFF, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_OFF, LED_ON, //M
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_ON
	},
	{
		LED_ON, LED_OFF, LED_ON, //N
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_ON
	},
	{
		LED_OFF, LED_ON, LED_OFF, //O
		LED_ON, LED_OFF, LED_ON,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_ON, LED_ON, LED_ON, //P
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_OFF, LED_OFF
	},
	{
		LED_ON, LED_ON, LED_OFF, //Q
		LED_ON, LED_ON, LED_OFF,
		LED_OFF, LED_OFF, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //R
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_OFF, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //S
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON, //T
		LED_OFF, LED_ON, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_ON, LED_OFF, LED_ON, //U
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_OFF, LED_ON, //V
		LED_ON, LED_OFF, LED_ON,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_ON, LED_OFF, LED_ON, //W
		LED_ON, LED_OFF, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_OFF, LED_ON, //X
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_OFF, LED_ON
	},
	{
		LED_ON, LED_OFF, LED_ON, //Y
		LED_OFF, LED_ON, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_ON, LED_ON, LED_ON, //Z
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_OFF, //Left bracket
		LED_ON, LED_OFF, LED_OFF,
		LED_ON, LED_ON, LED_OFF
	},
	{
		LED_ON, LED_OFF, LED_OFF, //Backslash
		LED_OFF, LED_ON, LED_OFF,
		LED_OFF, LED_OFF, LED_ON
	},
	{
		LED_OFF, LED_ON, LED_ON, //Right bracket
		LED_OFF, LED_OFF, LED_ON,
		LED_OFF, LED_ON, LED_ON
	},
	{
		LED_OFF, LED_ON, LED_OFF, //Caret
		LED_ON, LED_OFF, LED_ON,
		LED_OFF, LED_OFF, LED_OFF
	},
	{
		LED_OFF, LED_OFF, LED_OFF, //Underscore
		LED_OFF, LED_OFF, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_OFF, LED_OFF, //Backtick
		LED_OFF, LED_ON, LED_OFF,
		LED_OFF, LED_OFF, LED_OFF
	},
	{LED_OFF}, //a - Not implemented.
	{LED_OFF}, //b - Not implemented.
	{LED_OFF}, //c - Not implemented.
	{LED_OFF}, //d - Not implemented.
	{LED_OFF}, //e - Not implemented.
	{LED_OFF}, //f - Not implemented.
	{LED_OFF}, //g - Not implemented.
	{LED_OFF}, //h - Not implemented.
	{LED_OFF}, //i - Not implemented.
	{LED_OFF}, //j - Not implemented.
	{LED_OFF}, //k - Not implemented.
	{LED_OFF}, //l - Not implemented.
	{LED_OFF}, //m - Not implemented.
	{LED_OFF}, //n - Not implemented.
	{LED_OFF}, //o - Not implemented.
	{LED_OFF}, //p - Not implemented.
	{LED_OFF}, //q - Not implemented.
	{LED_OFF}, //r - Not implemented.
	{LED_OFF}, //s - Not implemented.
	{LED_OFF}, //t - Not implemented.
	{LED_OFF}, //u - Not implemented.
	{LED_OFF}, //v - Not implemented.
	{LED_OFF}, //w - Not implemented.
	{LED_OFF}, //x - Not implemented.
	{LED_OFF}, //z - Not implemented.
	{LED_OFF}, //a - Not implemented.
	{LED_OFF}, //Left curly brace - Not implemented.
	{
		LED_OFF, LED_ON, LED_OFF, //Pipe/vertical bar
		LED_OFF, LED_ON, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{LED_OFF}, //Right curly brace - Not implemented.
	{LED_OFF}, //Tilde - Not implemented.
	{LED_OFF}, //DEL - Not implemented. TODO figure out if we should have this in here.
};

int _debug_printf(const char *fmt, ...)
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

static BPrintfStatus _debug_print_char(const LEDState *grid)
{
    #ifdef BPRINTF_DEBUG
    for (int i = 0; i < CHAR_WIDTH; i++)
    {
        for (int j = 0; j < CHAR_HEIGHT; j++)
        {
            size_t idx = (i * CHAR_WIDTH) + j;
            if (putchar(grid[idx] == LED_ON ? '*' : ' ') == EOF)
            {
                return BPRINTF_PUTCHAR_ERR;
            }
        }
        if (putchar('\n') == EOF)
        {
            return BPRINTF_PUTCHAR_ERR;
        }
    }
    if (putchar('\n') == EOF)
    {
        return BPRINTF_PUTCHAR_ERR;
    }
    #endif
    return BPRINTF_SUCCESS;
}

void init_leds(void)
{
    #ifndef BPRINTF_DEBUG
    for (bsize_t i = 0; i < CHAR_WIDTH * CHAR_HEIGHT; i++)
    {
        gpio_init(LED_MAP[i]);
        gpio_set_dir(LED_MAP[i], GPIO_OUT);
    }
    #endif
}

static void clear_leds(void)
{
	#ifndef BPRINTF_DEBUG
    for (bsize_t i = 0; i < CHAR_WIDTH * CHAR_HEIGHT; i++)
    {
        gpio_put(LED_MAP[i], LED_OFF);
    }
	#endif
}

static BPrintfStatus send_to_board(const LEDState *leds)
{
    #ifdef BPRINTF_DEBUG
    return _debug_print_char(leds) < 0 ? BPRINTF_DEBUG_PRINT_ERR : BPRINTF_SUCCESS;
    #else
    for (bsize_t i = 0; i < CHAR_WIDTH * CHAR_HEIGHT; i++)
    {
        gpio_put(LED_MAP[i], leds[i]);
    }
    sleep_ms(SLEEP_MSEC);
    clear_leds();
    #endif
    return BPRINTF_SUCCESS;
}

BPrintfStatus bputchar(char c)
{
    return send_to_board(ASCII_MAP[(bsize_t)c]) == BPRINTF_SUCCESS ? BPRINTF_SUCCESS : BPRINTF_INVALID_CHAR_ERR;
}

int bprintf(const char *fmt, ...)
{
    char buffer[BPRINTF_BUF_LEN + 1];
    va_list args;
    va_start(args, fmt);

    //Parse format specifiers.
    bsize_t str_idx = 0;
    while (*fmt != '\0')
    {
        if (str_idx >= BPRINTF_BUF_LEN)
        {
            buffer[BPRINTF_BUF_LEN] = '\0';
            va_end(args);
            return str_idx;
        }
        if (*fmt == '%')
        {
            char c;
            long long n;
            char *s;
            switch(*(fmt + 1))
            {
                case 'c':
                    c = (char)va_arg(args, int); //We put "int" in as the type because char is promoted.
                    buffer[str_idx++] = c;
                    fmt++;
                    break;
                case 'd':
                case 'i':
                    n = (long long)va_arg(args, int);
                    s = stringifyn(n, (BBool)(n < 0));
                    goto copy_to_buffer;
                case 'l':
                    c = *(fmt + 2); //We want to see if it's a regular long or a long long.
                    if (c == 'd' || c == 'i')
                    {
                        n = (long long)va_arg(args, long); //Still casting to a long long since that's what n is.
                        s = stringifyn(n, (BBool)(n < 0));
                        fmt++;
                    }
                    else if (c == 'u')
                    {
                        n = (long long)va_arg(args, unsigned long); //See above.
                        s = stringifyn(n, (BBool)(n < 0));
                        fmt++;
                    }
                    else if (c == 'l')
                    {
                        c = *(fmt + 3); //Third and final potential piece of the format specifier.
                        fmt++;
                        if (c == 'd' || c == 'i')
                        {
                            n = va_arg(args, long long);
                            s = stringifyn(n, (BBool)(n < 0));
                            fmt++;
                        }
                        else if (c == 'u')
                        {
                            s = ulltos(va_arg(args, unsigned long long));
                            fmt++;
                        }
                        else
                        {
                            s = ""; //We hit something invalid.
                        }
                    }
                    else
                    {
                        s = ""; //Same as above.
                        
                    }
                    goto copy_to_buffer;
            case 's':
                s = va_arg(args, char*);
                goto copy_to_buffer;
            case 'R':
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
                break; //Nothing to put in the buffer if we can't print it. 
            }        
        }
        else
        {
            buffer[str_idx++] = *fmt; //Just putting a regular old character in.
            
        }
        fmt++;
    }
        
    fmt++;
    buffer[str_idx] = '\0';
    _debug_printf("%s\n", buffer);
    for (bsize_t i = 0; i < str_idx; i++)
    {
        #ifndef BPRINTF_SKIP_PUTCHAR
        if (bputchar(buffer[i]) == BPRINTF_PUTCHAR_ERR)
        {
            va_end(args);
            return -1;
        }
        #endif
		clear_leds();
    }
    va_end(args);
    return str_idx;
}

