/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef TEST_H
#define TEST_H

#include "bprintf.h"

BPrintfStatus test_special(void);
BPrintfStatus test_alpha_caps(void);
BPrintfStatus test_numeric(void);
BPrintfStatus test_signed_int_positive(void);
BPrintfStatus test_signed_int_negative(void);
BPrintfStatus test_signed_long_positive(void);
BPrintfStatus test_signed_long_negative(void);
BPrintfStatus test_unsigned_long(void);
BPrintfStatus test_signed_long_long_positive(void);
BPrintfStatus test_signed_long_long_negative(void);
BPrintfStatus test_unsigned_long_long(void);
BPrintfStatus test_zero(void);
BPrintfStatus test_char(void);
BPrintfStatus test_roman(void);
BPrintfStatus test_string(void);
BPrintfStatus test_buffer_overflow(void);

#endif //TEST_H
