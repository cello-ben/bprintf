/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <limits.h>

#include "bprintf.h"
#include "test.h"

BPrintfStatus test_special(void)
{
    if (_debug_printf("Testing special characters.\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    const char *special_chars = "\"'()+,-./:=[\\]^_`|";
    while (*special_chars != '\0')
    {
        if (bputchar(*special_chars) < 0)
        {
            return BPRINTF_PUTCHAR_ERR;
        }
        special_chars++;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_alpha_caps(void)
{
    if (_debug_printf("Testing capital letters.\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    
    const bsize_t ALPHA_CAPS_MIN = 65;
    const bsize_t ALPHA_CAPS_MAX = 90;

    for (bsize_t i = ALPHA_CAPS_MIN; i <= ALPHA_CAPS_MAX; i++)
	{
		if (bputchar(i) < 0)
        {
            return BPRINTF_PUTCHAR_ERR;
        }
	}
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_numeric(void)
{
    if (_debug_printf("Testing digits.\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }

    const bsize_t NUM_MIN = 48;
    const bsize_t NUM_MAX = 57;

    for (bsize_t i = NUM_MIN; i <= NUM_MAX; i++)
    {
        if (bputchar(i) < 0)
        {
            return BPRINTF_PUTCHAR_ERR;
        }
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_signed_int_positive(void)
{
    if (_debug_printf("Testing %%d format specifier.\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    return bprintf("IT IS FEBRUARY AKA %d", 2) < 0 ? BPRINTF_BPRINTF_ERR: BPRINTF_SUCCESS;
}

BPrintfStatus test_signed_int_negative(void)
{
    if (_debug_printf("Testing %%d format specifier.\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    if(bprintf("TEMPERATURE IS %d CELSIUS.", -3) < 0)
    {
    return BPRINTF_BPRINTF_ERR;
    }
    if(bprintf("%d IS A LOW NUMBER.", INT_MIN + 1) < 0) //TODO figure out a workaround for needing to add 1 to minimum values, if it exists.
    {
    return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_signed_long_positive(void)
{
    if (_debug_printf("Testing %%ld format specifier (positive).\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    if (bprintf("%ld IS A HIGH NUMBER.", LONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    if (_debug_printf("Testing %%li format specifier (positive).\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    if (bprintf("%li IS A HIGH NUMBER.", LONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
    
}

BPrintfStatus test_signed_long_negative(void)
{
    if (_debug_printf("Testing %%ld format specifier (negative).\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    if (bprintf("%ld IS A LOW NUMBER.", LONG_MIN + 1) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    if (_debug_printf("Testing %%li format specifier (negative).\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    if (bprintf("%li IS A LOW NUMBER.", LONG_MIN + 1) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_unsigned_long(void)
{
    
    if (_debug_printf("Testing %%lu format specifier.\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    return bprintf("%lu IS A HIGH NUMBER.", LONG_MAX) < 0 ? BPRINTF_BPRINTF_ERR : BPRINTF_SUCCESS;
}

BPrintfStatus test_signed_long_long_positive(void)
{
    if (_debug_printf("Testing %%lld format specifier (positive).\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    if (bprintf("%lld IS A HIGH NUMBER.", LLONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    if (_debug_printf("Testing %%lli format specifier (positive).\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    if (bprintf("%lli IS A HIGH NUMBER.", LLONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_signed_long_long_negative(void)
{
    if (_debug_printf("Testing %%lld format specifier (negative).\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    if (bprintf("%lld IS A HIGH NUMBER.", LLONG_MIN + 1) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    if (_debug_printf("Testing %%lli format specifier (negative).\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    if (bprintf("%lld IS A HIGH NUMBER.", LLONG_MIN + 1) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_unsigned_long_long(void)
{
    if (_debug_printf("Testing %%llu format specifier.\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    return bprintf("%llu IS A HIGH NUMBER.", ULLONG_MAX) < 0 ? BPRINTF_BPRINTF_ERR : BPRINTF_SUCCESS;
}

BPrintfStatus test_zeroes(void)
{
    if (_debug_printf("Testing 0 with %%d format specifier.\n") < 0) //TODO add more format specifiers (and then remove ternary operator from return)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    return bprintf("%d", 0) < 0 ? BPRINTF_BPRINTF_ERR: BPRINTF_SUCCESS;
}

BPrintfStatus test_char(void)
{
    if (_debug_printf("Testing %%c format specifier.\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    return bprintf("A CHARACTER IS %c.", 'C') < 0 ? BPRINTF_BPRINTF_ERR : BPRINTF_SUCCESS;
}

BPrintfStatus test_roman(void)
{
    if (_debug_printf("Testing %%R format specifier.\n") < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    return bprintf("%R WAS ROMAN...NOT ANYMORE.", "MMCMVI") < 0 ? BPRINTF_BPRINTF_ERR : BPRINTF_SUCCESS;
}

BPrintfStatus test_string(void)
{
    if (bprintf("MY NAME IS %s.", "BEN") < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    char *strptr = "STRING";
    if (bprintf("THIS IS A %s.", strptr) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    } 
    char strarr[] = "DIFFERENTLY-INITIALIZED STRING";
    if (bprintf("THIS IS A %s.", strarr) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    } 
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_buffer_overflow(void)
{
    char big_buffer[1024];
    for (int i = 0; i < 1023; i++)
    {
        big_buffer[i] = 'A';
    }
    big_buffer[1023] = '\0';
    int bprintf_res = bprintf("%s", big_buffer);
    if (bprintf_res < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    if (_debug_printf("Characters written (char array): %d\n", bprintf_res) < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    bprintf_res = bprintf("%s", &big_buffer); //TODO figure out if I indeed want to pass the address here.
    if (bprintf_res < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    if (_debug_printf("Characters written (address): %d\n", bprintf_res) < 0)
    {
        return BPRINTF_DEBUG_PRINT_ERR;
    }
    return bprintf_res > BPRINTF_BUF_LEN || bprintf_res < 0 ? BPRINTF_BPRINTF_ERR : BPRINTF_SUCCESS; //TODO make sure I'm checking the right things when returning.
}
