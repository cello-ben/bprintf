/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef BPRINTF_H
#define BPRINTF_H

#include <stdarg.h>

#define BPRINTF_DEBUG

#define BPRINTF_BUF_LEN 8192

#define CHAR_WIDTH 3
#define CHAR_HEIGHT 3

#define NUM_OFFSET 48
#define ALPHA_OFFSET 65

#define NUM_MIN 48
#define NUM_MAX 58

#define ALPHA_MIN 65
#define ALPHA_MAX 91

#define SLEEP_MSEC 1500

typedef enum LEDState {
	LED_OFF,
	LED_ON
} LEDState;

typedef enum BPrintfStatus {
	BPRINTF_SUCCESS,
	BPRINTF_INVALID_CHAR_ERR,
	BPRINTF_BOARD_SEND_ERR,
	BPRINTF_PUTCHAR_ERR
} BPrintfStatus;

typedef enum BBool {
	BFALSE,
	BTRUE
} BBool;

//TODO figure out why I can't have all definitions in here; is it because they're not #define constants?

int _debug_printf(const char *fmt, ...);
int _debug_print_char(const LEDState *grid);
BPrintfStatus off(int led);
BPrintfStatus on(int led);
BPrintfStatus send_to_board(const LEDState *leds);
BPrintfStatus bputchar(char c);
int bprintf(const char *fmt, ...);

#endif //BPRINTF_H

