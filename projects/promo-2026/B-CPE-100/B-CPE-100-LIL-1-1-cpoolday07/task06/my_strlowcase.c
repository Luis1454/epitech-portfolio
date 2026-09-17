/*
** EPITECH PROJECT, 2021
** my_lowcase
** File description:
** convert uppercases to lowercases
*/

char *my_strlowcase(char *str)
{
	int i = 0;

	while (str[i]) {
		if (65 <= str[i] && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	return str;
}