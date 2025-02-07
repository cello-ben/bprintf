/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef BPRINTF_H
#define BPRINTF_H

#define BPRINTF_DEBUG

#define CHAR_WIDTH 3
#define CHAR_HEIGHT 3

#define NUM_OFFSET 48
#define ALPHA_OFFSET 65

#define NUM_MIN 48
#define NUM_MAX 56

#define ALPHA_MIN 65
#define ALPHA_MAX 90

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
		LED_OFF, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	}
};

#define OUTPUT_ERROR -1

int _debug_print_char(const LEDState *grid);
BPrintfStatus off(int led);
BPrintfStatus on(int led);
BPrintfStatus send_to_board(const LEDState *leds);
BPrintfStatus bputchar(char c);
BPrintfStatus bprintf(const char *fmt, ...);

#endif //BPRINTF_H

