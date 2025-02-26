/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <limits.h>

#include "include/bprintf.h"
#include "test.h"

BPrintfStatus test_special(void)
{
    _debug_printf("Testing special characters.\n");
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
    _debug_printf("Testing capital letters.\n");
    
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
    _debug_printf("Testing digits.\n");

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
    _debug_printf("Testing %%d format specifier.\n");
     if(bprintf("IT IS FEBRUARY AKA %d", 2) < 0) //No lowercase letters implemented (not yet, at least).
     {
        return BPRINTF_BPRINTF_ERR;
     }
     return BPRINTF_SUCCESS;
}

BPrintfStatus test_signed_int_negative(void)
{
    _debug_printf("Testing %%d format specifier.\n");
     if(bprintf("TEMPERATURE IS %d CELSIUS.", -3) < 0)
     {
        return BPRINTF_BPRINTF_ERR;
     }
     if(bprintf("%d IS A LOW NUMBER.", INT_MIN + 1) < 0) //TODO figure out a workaround for needing to add 1 to minimum values.
     {
        return BPRINTF_BPRINTF_ERR;
     }
     return BPRINTF_SUCCESS;
}

BPrintfStatus test_signed_long_positive(void)
{
    _debug_printf("Testing %%ld format specifier (positive).\n");
    if (bprintf("%ld IS A HIGH NUMBER.", LONG_MAX) < 0) //TODO switch to ternary operator for simple functions (maybe).
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
    _debug_printf("Testing %%li format specifier (positive).\n");
    if (bprintf("%li IS A HIGH NUMBER.", LONG_MAX) < 0) //TODO switch to ternary operator for simple functions (maybe).
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_signed_long_negative(void)
{
    _debug_printf("Testing %%ld format specifier (negative).\n");
    if (bprintf("%ld IS A LOW NUMBER.", LONG_MIN + 1) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    _debug_printf("Testing %%li format specifier (negative).\n");
    if (bprintf("%li IS A LOW NUMBER.", LONG_MIN + 1) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_unsigned_long(void)
{
    _debug_printf("Testing %%lu format specifier.\n");
    if (bprintf("%lu IS A HIGH NUMBER.", LONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_signed_long_long_positive(void)
{
    _debug_printf("Testing %%lld format specifier (positive).\n");
    if (bprintf("%lld IS A HIGH NUMBER.", LLONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    _debug_printf("Testing %%lli format specifier (positive).\n");
    if (bprintf("%lli IS A HIGH NUMBER.", LLONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_signed_long_long_negative(void)
{
    _debug_printf("Testing %%lld format specifier (negative).\n");
    if (bprintf("%lld IS A HIGH NUMBER.", LLONG_MIN + 1) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    _debug_printf("Testing %%lli format specifier (negative).\n");
    if (bprintf("%lld IS A HIGH NUMBER.", LLONG_MIN + 1) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_unsigned_long_long(void)
{
    _debug_printf("Testing %%llu format specifier.\n");
    if (bprintf("%llu IS A HIGH NUMBER.", ULLONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_char(void)
{
    _debug_printf("Testing %%c format specifier.\n");
    if(bprintf("A CHARACTER IS %c.", 'C') < 0)
     {
        return BPRINTF_BPRINTF_ERR;
     }
     return BPRINTF_SUCCESS;
}

BPrintfStatus test_roman(void)
{
    if (bprintf("%R WAS ROMAN, MY FRIEND.", "MCDIV") < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_string(void)
{
    if (bprintf("MY NAME IS %s.", "BEN") < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    char str[] = "DIFFERENTLY-INITIALIZED STRING";
    if (bprintf("THIS IS A %s.", str) < 0)
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
    if (bprintf_res < 0) //TODO figure out if I indeed want to pass the address here.
    {
        return BPRINTF_BPRINTF_ERR;
    }
    _debug_printf("Characters written (char array): %d\n", bprintf_res);
    bprintf_res = bprintf("%s", &big_buffer);
    if (bprintf_res < 0) //TODO figure out if I indeed want to pass the address here.
    {
        return BPRINTF_BPRINTF_ERR;
    }
    _debug_printf("Characters written (address): %d\n", bprintf_res);
    return bprintf_res > BPRINTF_BUF_LEN ? BPRINTF_BPRINTF_ERR : BPRINTF_SUCCESS;
}
