#include <bprintf.h>
#include <limits.h>
#include <test.h>

BPrintfStatus test_special(void)
{
    _debug_printf("Testing special characters.\n");
    const char *SPECIAL_CHARS = " .-";
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
    for (int i = ALPHA_MIN; i < ALPHA_MAX; i++)
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

