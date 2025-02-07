/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef BPRINTF_H
#define BPRINTF_H

#define CHAR_WIDTH 3
#define CHAR_HEIGHT 3

#define NUM_OFFSET 48
#define ALPHA_OFFSET 65

typedef enum LEDState {
	LED_OFF,
	LED_ON
} LEDState;

const LEDState SPACE[CHAR_WIDTH * CHAR_HEIGHT] = {LED_OFF};
const LEDState PERIOD[CHAR_WIDTH * CHAR_HEIGHT] = {
		LED_OFF, LED_OFF, LED_OFF,
		LED_OFF, LED_OFF, LED_OFF,
		LED_OFF, LED_OFF, LED_ON
	};


const LEDState NUMS[10][CHAR_WIDTH * CHAR_HEIGHT] = {
	{
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_OFF, LED_ON,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_OFF,
		LED_ON, LED_ON, LED_OFF,
		LED_OFF, LED_ON, LED_OFF
	},
	{
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_ON, LED_ON
	},
	{
		LED_OFF, LED_ON, LED_ON,
		LED_OFF, LED_ON, LED_ON,
		LED_OFF, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_OFF, LED_ON,
		LED_OFF, LED_OFF, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON
	},
	{
		LED_ON, LED_ON, LED_ON,
		LED_ON, LED_ON, LED_ON,
		LED_OFF, LED_OFF, LED_ON
	}
};


#define OUTPUT_ERROR -1

int light(int led);
int send_to_board(int *leds);
int bputchar(char c);
int bprintf(const char *fmt, ...);

#endif //BPRINTF_H

