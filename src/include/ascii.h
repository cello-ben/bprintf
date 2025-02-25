#ifndef ASCII_H
	#define ASCII_H

	#include "bprintf.h"

	static const LEDState ASCII_MAP[128][9] = { //TODO figure out why this can only be included in one file.
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
			LED_ON, LED_OFF, LED_OFF, //Grave accent/backtick
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

#endif //ASCII_H
