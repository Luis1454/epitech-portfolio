/*
** EPITECH PROJECT, 2021
** cat.c
** File description:
** cat command in C
*/

#include <unistd.h>
#include <fcntl.h>

void main(int argc, char const *argv[])
{
	char txt[128];
	int file;
	int len;

	open("test", O_RDONLY);

	if (file == -1) {
		len = read(file, txt, 127);
		txt[len] = 0;
		write(0, &txt, len);
	}
}
