#include <bprintf.h>

#include <blib.h>

char *itos(int n)
{
	// BBool negative = n < 0; 
	char tmp[11];
	bsize_t idx = 0;
	while (n)
	{
		tmp[idx++] = (n % 10) + NUM_OFFSET;
		n /= 10;
	}
	// const bsize_t len = idx + 1;
	char *res = "00000000000";
	// res[idx] = '\0';
	_debug_printf("%s\n", res);
	// for (bsize_t i = 0; i < len; i++)
	// {
	// 	res[i] = tmp[--idx];
	// }
	return res;
}
