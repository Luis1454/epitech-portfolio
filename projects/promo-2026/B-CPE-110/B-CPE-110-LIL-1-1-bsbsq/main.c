#include <fcntl.h> 
#include <stdio.h> 
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

void get_array(char **arr, int Ylen)
{
	for (int i = 0; i < Ylen; i++)
		arr[i] = malloc(sizeof(char *) * Ylen);
}

void print_array(char **arr, int a)
{
	for (int i = 0; i < a; i++) {
		printf("%s", arr[i]);
	}
}

int get_mask(char **arr, int size, int a, int b)
{
	int origin = '+';
	int state = origin;

	for (int i = 0; i < size; i++) {
		//printf("%c", arr[i][b]);
		if (arr[i + a][b] == 'o' && state == origin)
			state = ' ';
	}
	//printf("\n");

	return state;
}

char *find_next_place(char **arr, int Xlen, int Ylen, int nb)
{
	char *head = malloc(sizeof(char) * 2);

	for (int i = 0; i < Xlen; i++) {
		for (int j = 0; j < Ylen; j++) {
			if (arr[i][j] - 48 == nb) {
				head[0] = i;
				head[1] = j;
				return head;
			}
		}
	}
	return "0";
}

void draw_square(char **arr, int x, int y, int size)
{
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] != 'o' && arr[i][j] != '\n')
				arr[i][j] = 'X';
		}
	}
}

int count_squares(char **arr, int Xlen, int Ylen, int size)
{
	char **mask = malloc(sizeof(char *) * Xlen);
	get_array(mask, Ylen);
	char **layer_3 = malloc(sizeof(char *) * Xlen);
	get_array(layer_3, Ylen);
	int exist;

	for (int i = 0; i < Xlen - size; i++) {
		for (int j = 0; j < Ylen - size; j++) {
			mask[i][j] = get_mask(arr, size, i, j);
		}
	}

	for (int i = 0; i < Xlen - size; i++) {
		for (int j = 0; j < Ylen - size; j++) {
			exist = 1;
			for (int k = 0; k < size; k++) {
				if (mask[i][j + k] == ' ' && exist)
					exist = 0;
			}

			if (exist)
				layer_3[i][j] = size + 48;
			else
				layer_3[i][j] = ' ';
		}
	}

	printf("\n");
	for (int i = 0; i < Xlen - size; i++) {
		printf("%s\n", layer_3[i]);
	}

	for (int i = 0; i < Xlen - size; i++) {
		printf("%s\n", mask[i]);
	}

	char *head = find_next_place(layer_3, Xlen, Ylen, size);

	draw_square(arr, head[0], head[1], size);

	printf("(%i, %i)\n", find_next_place(layer_3, Xlen, Ylen, size)[0], find_next_place(layer_3, Xlen, Ylen, size)[1]);

	return 1;
}

void get_map()
{
	int fd = open("mouli_maps/intermediate_map_100_100", O_RDONLY);
	char str_nb[15];
	char test[8000000];
	int len_line = 100;
	int j = 0;
	int n = 0;
	int i = 0;

	while (str_nb[i - 1] != '\n') {
		read(fd, &str_nb[i], 1);
		i++;
	}

	str_nb[my_strlen(str_nb) - 1] = 0;
	int nb_line = my_getnbr(str_nb);
	char **arr = malloc(sizeof(char *) * nb_line);

	get_array(arr, len_line);

	printf("nb line: %i\n", nb_line);

	while (n < nb_line) {
		read(fd, &arr[n][j], len_line);
		if (arr[n][j] == '\n'){
			arr[n][j] = 0;
			j = 0;
			n++;
		} else {
			len_line++;
			j++;
		}
	}

	len_line = 100;

	count_squares(arr, nb_line, len_line, 3);

	print_array(arr, nb_line);
}

int main(int argc, char const *argv[])
{
	get_map();
	return 0;
}
