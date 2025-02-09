/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef BLIB_H
#define BLIB_H

#define INT_MAX_DIGITS_LEN 10
#define LONG_MAX_DIGITS_LEN 19
#define ULONG_MAX_DIGITS_LEN 20
#define LONG_LONG_MAX_DIGITS_LEN 19
#define ULONG_LONG_MAX_DIGITS_LEN 20

#define ABS(n) (n) > 0 ? (n) : (-n) //TODO check for correctness re: parentheses.

typedef unsigned int bsize_t;

typedef enum BBool {
	BFALSE,
	BTRUE
} BBool;

char *itos(int n);
char *rtods(const char *s);
char *ltos(long n);
char *ultos(unsigned long n);
char *lltos(long long n);
char *ulltos(unsigned long long n);

#endif
