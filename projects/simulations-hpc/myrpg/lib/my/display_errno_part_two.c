/*
** EPITECH PROJECT, 2022
** display_errno_part_two.c
** File description:
** get errno msg
*/

int my_print_error(char const *str);

int display_errno_f(int errno)
{
    switch (errno) {
        case 26:
            my_print_error("Not a typewriter");
            break;
        case 27:
            my_print_error("Text file busy");
            break;
        case 28:
            my_print_error("File too large");
            break;
        case 29:
            my_print_error("Illegal seek");
            break;
        case 30:
            my_print_error("Read-only file system");
            break;
    }
    return 0;
}

int display_errno_g(int errno)
{
    switch (errno) {
        case 32:
            my_print_error("Broken pipe");
            break;
        case 33:
            my_print_error("Math argument out of domain of func");
            break;
        case 34:
            my_print_error("Math result not representable");
            break;
        case 35:
            my_print_error("Resource deadlock would occur");
            break;
        case 36:
            my_print_error("File name too long");
            break;
    }
    return 0;
}

int display_errno_h(int errno)
{
    switch (errno) {
        case 37:
            my_print_error("No record locks available");
            break;
        case 38:
            my_print_error("Function not implemented");
            break;
        case 39:
            my_print_error("Directory not empty");
            break;
        case 40:
            my_print_error("Too many symbolic links encountered");
            break;
        case 42:
            my_print_error("No message of desired type");
            break;
    }
    return 0;
}

int display_errno_i(int errno)
{
    switch (errno) {
        case 43:
            my_print_error("Identifier removed");
            break;
        case 44:
            my_print_error("Channel number out of range");
            break;
        case 45:
            my_print_error("Level 2 not synchronized");
            break;
        case 46:
            my_print_error("Level 3 halted");
            break;
        case 47:
            my_print_error("Level 3 reset");
            break;
    }
    return 0;
}

int display_errno_j(int errno)
{
    switch (errno) {
        case 48:
            my_print_error("Link number out of range");
            break;
        case 49:
            my_print_error("Protocol driver not attached");
            break;
        case 50:
            my_print_error("No CSI structure available");
            break;
        case 51:
            my_print_error("Level 2 halted");
            break;
        case 52:
            my_print_error("Invalid exchange");
            break;
    }
    return 0;
}
