#include <stdlib.h>

char *duplicate_string(char const *src)
{
	int i;
	char *out = malloc(sizeof(char) * my_strlen(src));

	for (i = 0; i < my_strlen(src); i++)
		out[i] = src[i];
	return out;
}
