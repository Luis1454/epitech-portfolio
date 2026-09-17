/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** find a pattern in a string
*/

int my_strlen(char *str);

char *my_strstr(char *str, char const *to_find)
{
    char out[my_strlen(str)];
    int i = 0;
    int j = 0;
    int k;

    while (str[i]){
        j = 0;
        while (str[i + j] == to_find[j]) {
            if (j >= my_strlen(to_find) - 1) {
                k = i;
                while (str[i]) {
                    out[i - k] = str[i];
                    i++;
                }
                out[i - k] = 0;
                return out;
            }
            j++;
        }
        i++;
    }
    return "";
}
