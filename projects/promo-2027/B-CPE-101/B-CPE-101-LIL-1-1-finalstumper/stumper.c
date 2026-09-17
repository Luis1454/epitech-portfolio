/*
** EPITECH PROJECT, 2022
** stumper.c
** File description:
** core file for final stumper
*/

#include "include/my.h"

int display_message(char *buf, int nb, int state)
{
    int line = 0;
    int row = 0;

    for (; buf && buf[line] != '\n'; line++);
    for (int i = 0; buf[i]; i++)
        row += buf[i] == '\n';
    if (state)
        my_putstr(" || ");
    my_putstr("[rush1-");
    my_put_nbr(nb);
    my_putstr("] ");
    my_put_nbr(line);
    my_putchar(' ');
    my_put_nbr(row);
    return 1;
}

char *get_corner(char *tab, char *buf, int line, int row)
{
    int i = 0;

    tab[0] = buf[0];
    for (; buf[i] && buf[i] != '\n'; i++);
    tab[1] = buf[i - 1];
    tab[2] = 0;
    for (; buf[i]; i++);
    tab[3] = buf[(line + 1) * row - 2];
    return tab;
}

int handle_special_cases(char *tab, char *buf)
{
    int state = 0;

    if (tab[0] == tab[1])
        state = display_message(buf, 3, state);
    if (tab[0] != tab[1] && tab[3] == 'C' || tab[3] == 'B')
        state = display_message(buf, 4, state);
    if (tab[0] != tab[1] && (tab[3] == 'A') || tab[3] == 'B')
        state = display_message(buf, 5, state);
    return state;
}

int rush3(char *buf)
{
  char *tab;
  int line = 0;
  int row = 0;
  int state = 0;

   
  for (; buf && buf[line] != '\n'; line++);
  for (int i = 0; buf[i]; i++)
    row += buf[i] == '\n';
  if (!row || !line) {
    write(2, "none\n", 6);
    return 84;
  }
  tab = malloc(sizeof(char) * 4);
  tab = get_corner(tab, buf, line, row);
  if (tab[0] == 'o')
    display_message(buf, 1, 0);
  else if (tab[0] == '/' || tab[0] == '*')
    display_message(buf, 2, 0);
  else {
    state = !handle_special_cases(tab, buf);
  }
  my_putstr(state ? "none\n" : "\n");
  free(tab);
  return 0;
}
