/*
** EPITECH PROJECT, 2022
** my_macro_abs.h
** File description:
** macro handling
*/

#pragma once

#ifndef ABS
    #define ABS(value)(value < 0 ? -value : value)
#endif /* ABS */

#ifndef MIN
    #define MIN(a, b)(a < b ? a : b)
#endif /* MIN */

#ifndef MAX
    #define MAX(a, b)(a > b ? a : b)
#endif /* MAX */

#define TRUE 1
#define FALSE 0

#define S_TRUE "TRUE"
#define S_FALSE "FALSE"
