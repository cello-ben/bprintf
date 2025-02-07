# Copyright 2025 Benjamin Fryxell
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SRC_DIR = src
INC = -I$(SRC_DIR)/include
CFLAGS = -Wall -Wpedantic -Wextra  -Wno-unused-parameter -Wno-unused-function -Werror -std=gnu99

all: #Default to static.
	make static

static:
	gcc -c -o static_lib.o $(SRC_DIR)/bprintf.c $(INC) $(CFLAGS) -ffreestanding -O0 #TODO figure out if this is what I should use for an embedded situation.
	ar rcs libbprintf.a static_lib.o
	rm -rf *.o

debug:
	gcc -g -o bprintf_debug $(SRC_DIR)/main.c $(INC) $(CFLAGS) 

clean:
	rm -rf bprintf_debug *.a *.dSYM #TODO figure out if more things need to be removed later.
