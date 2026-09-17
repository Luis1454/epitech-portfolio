/*
** EPITECH PROJECT, 2022
** display_errno_part_five.c
** File description:
** get errno msg
*/

int my_print_error(char const *str);

int display_errno_u(int errno)
{
    switch (errno) {
        case 104:
            my_print_error("Connection reset by peer");
            break;
        case 105:
            my_print_error("No buffer space available");
            break;
        case 106:
            my_print_error("Transport endpoint is already connected");
            break;
        case 107:
            my_print_error("Transport endpoint is not connected");
            break;
        case 108:
            my_print_error("Cannot send after transport endpoint shutdown");
            break;
    }
    return 0;
}

int display_errno_v(int errno)
{
    switch (errno) {
        case 109:
            my_print_error("Too many references: cannot splice");
            break;
        case 110:
            my_print_error("Connection timed out");
            break;
        case 111:
            my_print_error("Connection refused");
            break;
        case 112:
            my_print_error("Host is down");
            break;
        case 113:
            my_print_error("No route to host");
            break;
    }
    return 0;
}

int display_errno_w(int errno)
{
    switch (errno) {
        case 114:
            my_print_error("Operation already in progress");
            break;
        case 115:
            my_print_error("Operation now in progress");
            break;
        case 116:
            my_print_error("Stale NFS file handle");
            break;
        case 117:
            my_print_error("Structure needs cleaning");
            break;
        case 118:
            my_print_error("Not a XENIX named type file");
            break;
    }
    return 0;
}

int display_errno_x(int errno)
{
    switch (errno) {
        case 119:
            my_print_error("No XENIX semaphores available");
            break;
        case 120:
            my_print_error("Is a named type file");
            break;
        case 121:
            my_print_error("Remote I/O error");
            break;
        case 122:
            my_print_error("Quota exceeded");
            break;
        case 123:
            my_print_error("No medium found");
            break;
    }
    return 0;
}

int display_errno_y(int errno)
{
    switch (errno) {
        case 119:
            my_print_error("No XENIX semaphores available");
            break;
        case 120:
            my_print_error("Is a named type file");
            break;
        case 121:
            my_print_error("Remote I/O error");
            break;
        case 122:
            my_print_error("Quota exceeded");
            break;
        case 123:
            my_print_error("No medium found");
            break;
    }
    return 0;
}
