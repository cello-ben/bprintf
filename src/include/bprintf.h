/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef BPRINTF_H
	#define BPRINTF_H

	#define BPRINTF_DEBUG
	#define BPRINTF_SKIP_PUTCHAR

	#define BPRINTF_BUF_LEN 512 //Default Pico stack size is 2048. This should be a safe number that leaves us plenty of wiggle room. And let's be real, who wants to sit and wait for an LED matrix to light up 512 different times?

	#define CHAR_WIDTH 3
	#define CHAR_HEIGHT 3

	#define NUM_OFFSET 48
	#define ALPHA_OFFSET 65

	#define SLEEP_MSEC 750

	typedef unsigned int bsize_t;

	typedef enum LEDState {
		LED_OFF,
		LED_ON
	} LEDState;

	typedef enum BPrintfStatus {
		BPRINTF_BPRINTF_ERR = -1,
		BPRINTF_SUCCESS,
		BPRINTF_INVALID_CHAR_ERR,
		BPRINTF_BOARD_SEND_ERR,
		BPRINTF_PUTCHAR_ERR,
		BPRINTF_DEBUG_PRINT_ERR
	} BPrintfStatus;

	int _debug_printf(const char *fmt, ...);
	static BPrintfStatus _debug_print_char(const LEDState *grid);
	void init_leds(void);
	static void clear_leds(void);
	static BPrintfStatus send_to_board(const LEDState *leds);
	BPrintfStatus bputchar(char c);
	int bprintf(const char *fmt, ...);

#endif //BPRINTF_H
