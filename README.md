# bprintf
[![Build Debug](https://github.com/cello-ben/bprintf/actions/workflows/build.yaml/badge.svg)](https://github.com/cello-ben/bprintf/actions/workflows/build.yaml)

This is my first foray into embedded programming. However, it is fully testable in a desktop environment. It's a work in progress, and with that in mind, here are (some) next steps:

- Implement basic floating point/double format specifiers.

- Audit the code to be more defensive and prevent overflows and the like. The stakes are low since this project is purely for fun and learning, but good practice is good practice.

- Expand both the breadboard setup and the code to support a 4x4 matrix instead, in order to make the characters look like...errr...the characters.

# Format Specifiers Currently Implemented

`%c` - Prints a single character.

`%s` - Prints a string from a literal or char pointer.

`%d/%i` - Prints a signed int.

`%ld`/`%li` - Prints a signed long.

`%lu` - Prints an unsigned long.

`%lld`/`lli` - Prints a signed long long.

`%llu` - Prints an unsigned long long.

`%R` - Prints the decimal representation of a Roman numeral from a string literal or char pointer.

# Building

## Local Development
If you want to test it out on a computer, you can instead run `make debug`. Once finished, `make clean` will get rid of everything created by `make`, including the executable. To run the tests in `driver.c`, simply run the bprintf_debug executable. The new Roman numeral feature can be easily tested. It is commented out at present, but can be uncommented for testing when functionality is implemented.

## Board Deployment
The Pico SDK has a most unwieldy build system, based upon CMake. Once set up, though, it is relatively straightforward to use with VS Code. 

First, clone the project and open it up in VS Code. Then, you can install the Raspberry Pi Pico extension. Assuming you have CMake installed, you should be able to click the microcontroller-looking icon on the sidebar and choose "Import Project". Select the current working directory and whatever options you desire. I kept it at its defaults when testing, except that I went with SDK version 2.0.0 (not default at time of writing).

Once imported, the toolchain should install automatically. You may notice that it has created `pico_sdk_import.cmake`, as well as a `.vscode` directory and a `.build` directory. Finally, you can choose to run the project on a Raspberry Pi Pico connected in BOOTSEL mode by, in the panel revealed by the microcontroller-looking icon, choosing "Run Project (USB)".

If it is not working, you may need to change what Pico version you are using under "Switch Board" (in that same panel).

# Freestanding

This is designed to be built without libc and be bundled up in a tiny package. However, at least for the time being, I am using `stdarg.h` and `limits.h`, based upon [this link](https://wiki.osdev.org/Implications_of_writing_a_freestanding_C_project#Headers_available_as_of_C89), helpfully given to me by a kind Redditor.

# Supported Characters

At present, there are many ASCII characters that have yet to be implemented. Part of this is due to the limitations of a 3x3 matrix of LEDs, but part of it is also for simplicity. No valid ASCII value (0-127) will cause an error. However, characters that have not been implemented wil be skipped.

### Currently Implemented
- Capital letters
- Numbers
- The following special characters (in ASCII order):
    ```
    "'()+,-./:=[\]^_`|
    ```
- Space/blank character

# Debug Defines

There are a couple of defines you can use for help debugging. The main one is `BPRINTF_DEBUG`, which allows more use of libc to use (real) `printf`. The other is `BPRINTF_SKIP_PUTCHAR`, which bypasses the calls to `bputchar`, thus eliminating some clutter in the terminal. Both should be defined in `bprintf.h`. 

Make sure that neither of these are defined when you deploy to a Raspberry Pi Pico. In the future, I may see about undefining them automatically using CMake, but I am unsure at this time.

# Generative AI Disclosure

The code herein was written **without** the help of generative AI. When I got stuck, I either researched or reached out for help on r/cprogramming. I am deeply grateful for the latter. Generative AI **was** used as an advisor for setting up the breadboard, as well as for basic electronics troubleshooting as I got set up for my first time doing embedded development.
