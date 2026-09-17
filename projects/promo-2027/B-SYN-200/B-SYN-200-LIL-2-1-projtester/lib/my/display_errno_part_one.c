/*
** EPITECH PROJECT, 2022
** display_errno_part_one.c
** File description:
** get errno msg
*/

int my_print_error(char const *str);

int display_errno_a(int errno)
{
    switch (errno) {
        case 1:
            my_print_error("Operation not permitted");
            break;
        case 2:
            my_print_error("No such file or directory");
            break;
        case 3:
            my_print_error("No such process");
            break;
        case 4:
            my_print_error("Interrupted system call");
            break;
        case 5:
            my_print_error("I/O error");
            break;
    }
    return 0;
}

int display_errno_b(int errno)
{
    switch (errno) {
        case 6:
            my_print_error("No such device or address");
            break;
        case 7:
            my_print_error("Argument list too long");
            break;
        case 8:
            my_print_error("Exec format error");
            break;
        case 9:
            my_print_error("Bad file number");
            break;
        case 10:
            my_print_error("No child processes");
            break;
    }
    return 0;
}

int display_errno_c(int errno)
{
    switch (errno) {
        case 11:
            my_print_error("Try again");
            break;
        case 12:
            my_print_error("Out of memory");
            break;
        case 13:
            my_print_error("Permission denied");
            break;
        case 14:
            my_print_error("Bad address");
            break;
        case 15:
            my_print_error("Block device required");
            break;
    }
    return 0;
}

int display_errno_d(int errno)
{
    switch (errno) {
        case 16:
            my_print_error("Device or resource busy");
            break;
        case 17:
            my_print_error("File exists");
            break;
        case 18:
            my_print_error("Cross-device link");
            break;
        case 19:
            my_print_error("No such device");
            break;
        case 20:
            my_print_error("Not a directory");
            break;
    }
    return 0;
}

int display_errno_e(int errno)
{
    switch (errno) {
        case 21:
            my_print_error("Is a directory");
            break;
        case 22:
            my_print_error("Invalid argument");
            break;
        case 23:
            my_print_error("File table overflow");
            break;
        case 24:
            my_print_error("Too many open files");
            break;
        case 25:
            my_print_error("Cross-device link");
            break;
    }
    return 0;
}
