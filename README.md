# bprintf

I'm Ben and I want to create my own `printf`...so...`bprintf`. More to come soon, once I get the Raspberry Pi Pico in hand.

### Format Specifiers Currently Implemented

`%c` - Print a single character

`%s` - Print a string from a literal or char pointer

`%d/%i` - Print a signed int

`%ld`/`%li` - Print a signed long

`%lu` - Print an unsigned long

`%lld`/`lli` - Print a signed long long

`%llu` - Print an unsigned long long

`%R` - Print the decimal representation of a Roman numeral from a string literal or char pointer

# Freestanding

This is designed to be built without libc and be bundled up in a tiny package. However, at least for the time being, I am using `stdarg.h` and `limits.h`, based upon [this link](https://wiki.osdev.org/Implications_of_writing_a_freestanding_C_project#Headers_available_as_of_C89), helpfully given to me by a kind Redditor.

# Supported Characters

At present, there are many ASCII characters that have yet to be implemented. Part of this is due to the limitations of a 3x3 matrix of LEDs, but part of it is also for simplicity. Any ASCII value from 0-127 will work without error. However, characters that have not been implemented wil be skipped. Currently, capital letters, all numbers, the period, the underscore, the hyphen/negative sign, and the pipe/vertical bar are implemented, as well as a space.

# Debug Defines

There are a couple of defines you can use for help debugging. The main one is `BPRINTF_DEBUG`, which allows more use of libc to use (real) `printf`. The other is `BPRINTF_SKIP_PUTCHAR`, which bypasses the calls to `bputchar`, thus eliminating some clutter in the terminal. Both should be defined in `bprintf.h`. 

# Generative AI Disclosure

The code herein was written **without** the help of generative AI. Generative AI **was** used as an advisor for setting up the breadboard, as well as for basic troubleshooting as I got set up for my first time doing embedded development. For full transparency, those conversations can be seen [here](https://chatgpt.com/share/67a88d01-9770-800b-b29e-fee49701916c), [here](https://chatgpt.com/share/67a9390c-282c-800b-8864-05604baeee18), and [here](https://chatgpt.com/share/67a9390c-282c-800b-8864-05604baeee18).

# License

MIT License:

Copyright 2025 Benjamin Fryxell

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.