/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "bprintf.h"

#ifdef BPRINTF_DEBUG
	#include <assert.h>
	#include <limits.h>
	#include <test.h>
#else
	#include "pico/stdlib.h"
#endif

int main(void)
{
	int print_res = 0;
	#ifdef BPRINTF_DEBUG
		assert(test_special() == BPRINTF_SUCCESS);
		assert(test_alpha_caps() == BPRINTF_SUCCESS);
		assert(test_numeric() == BPRINTF_SUCCESS);
		assert(test_signed_int_positive() == BPRINTF_SUCCESS);
		assert(test_signed_int_negative() == BPRINTF_SUCCESS);
		assert(test_signed_long_positive() == BPRINTF_SUCCESS);
		assert(test_signed_long_negative() == BPRINTF_SUCCESS);
		assert(test_unsigned_long() == BPRINTF_SUCCESS);
		assert(test_signed_long_long_positive() == BPRINTF_SUCCESS);
		assert(test_signed_long_long_negative() == BPRINTF_SUCCESS);
		assert(test_unsigned_long_long() == BPRINTF_SUCCESS);
		assert(test_zeroes() == BPRINTF_SUCCESS);
		assert(test_char() == BPRINTF_SUCCESS);
		assert(test_roman() == BPRINTF_SUCCESS);
		assert(test_string() == BPRINTF_SUCCESS);
		assert(test_buffer_overflow() == BPRINTF_SUCCESS);
		print_res = _debug_printf("All tests passed!\n");
	#else
		init_leds();
		print_res = bprintf("HELLO WORLD");
	#endif
	return print_res;
}
