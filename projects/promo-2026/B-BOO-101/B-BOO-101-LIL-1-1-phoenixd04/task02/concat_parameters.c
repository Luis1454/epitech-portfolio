#include <stdlib.h>

static int get_len(int ac, char *av[])
{
	int j;
	int len = 0;

	for (int i = 0; i < ac; i++) {
		j = 0;
		while (av[i][j]) {
			len++;
			j++;
		}
	}
	return len;
}

char *concat_parameters(int ac, char *av[])
{
	char *out = malloc(sizeof(char) * ac);
	int j;

	printf("%i\n", get_len(ac, av));
}
