/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday06-mathis.zucchero
** File description:
** my_strlowcase.c
*/

char *my_strlowcase(char *str)
{
    int low = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            low = str[i] + 32;
            str[i] += 32;
        }
    }
    return (str);
}
