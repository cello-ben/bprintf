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

