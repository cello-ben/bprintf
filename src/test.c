#include <bprintf.h>
#include <test.h>

#ifdef BPRINTF_DEBUG
    #include <limits.h>
#endif

BPrintfStatus test_special(void)
{
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

BPrintfStatus test_alpha(void)
{
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
     if(bprintf("IT IS FEBRUARY AKA %d", 2) < 0) //No lowercase letters implemented (not yet, at least).
     {
        return BPRINTF_BPRINTF_ERR;
     }
     return BPRINTF_SUCCESS;
}

BPrintfStatus test_char(void)
{
    if(bprintf("A CHARACTER IS %c.", 'C') < 0)
     {
        return BPRINTF_BPRINTF_ERR;
     }
     return BPRINTF_SUCCESS;
}

BPrintfStatus test_signed_long(void)
{
    if (bprintf("%ld IS A HIGH NUMBER.", LONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_unsigned_long(void)
{
    if (bprintf("%lu IS A HIGH NUMBER.", ULONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_signed_long_long(void)
{
    if (bprintf("%lld IS A HIGH NUMBER.", LONG_LONG_MAX) < 0)
    {
        return BPRINTF_BPRINTF_ERR;
    }
    return BPRINTF_SUCCESS;
}

BPrintfStatus test_unsigned_long_long(void)
{
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

