/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <bprintf.h>
#include <limits.h>
#include <test.h>

BPrintfStatus test_special(void)
{
    _debug_printf("Testing special characters.\n");
    const char *SPECIAL_CHARS = " .-_";
    while (*SPECIAL_CHARS != '\0')
    {
        if (bputchar(*SPECIAL_CHARS) < 0)
        {
            return BPRINTF_PUTCHAR_ERR;
        }
        SPECIAL_CHARS++;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_alpha_caps(void)
{
    _debug_printf("Testing capital letters.\n");
    for (int i = ALPHA_CAPS_MIN; i < ALPHA_CAPS_MAX; i++)
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
    for (int i = NUM_MIN; i < NUM_MAX; i++)
    {
        if (bputchar(i) < 0)
        {
            return BPRINTF_PUTCHAR_ERR;
        }
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_decimal(void)
{
    _debug_printf("Testing %%d format specifier.\n");
     if(bprintf("IT IS FEBRUARY AKA %d", 2) < 0) //No lowercase letters implemented (not yet, at least).
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

BPrintfStatus test_signed_long(void)
{
    _debug_printf("Testing %%ld format specifier.\n");
    if (bprintf("%ld IS A HIGH NUMBER.", LONG_MAX) < 0)
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

BPrintfStatus test_signed_long_long(void)
{
    _debug_printf("Testing %%lld format specifier.\n");
    if (bprintf("%lld IS A HIGH NUMBER.", LONG_LONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_unsigned_long_long(void)
{
    _debug_printf("Testing %%llu format specifier.\n");
    if (bprintf("%llu IS A HIGH NUMBER.", ULONG_LONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_roman(void)
{
    if (bprintf("%R WAS ROMAN.", "MVII") < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_string(void)
{
    if (bprintf("MY NAME IS %s", "BEN") < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}
