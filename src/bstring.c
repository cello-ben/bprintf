#include <bstring.h>

unsigned int bstrlen(const char *s)
{
	const char *tmp = s;
	unsigned int len = 0;
	while (*tmp != '\0')
	{
		len++;
		tmp++;
	}
	return len;
}
