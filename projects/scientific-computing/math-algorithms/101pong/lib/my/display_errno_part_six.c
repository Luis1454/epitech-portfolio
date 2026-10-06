/*
** EPITECH PROJECT, 2022
** display_errno_part_six.c
** File description:
** get errno msg
*/

int my_print_error(char const *str);

int display_errno_z(int errno)
{
    switch (errno) {
        case 124:
            my_print_error("Wrong medium type");
            break;
        case 125:
            my_print_error("Operation Canceled");
            break;
        case 126:
            my_print_error("Required key not available");
            break;
        case 127:
            my_print_error("Key has expired");
            break;
        case 128:
            my_print_error("Key has been revoked");
            break;
    }
    return 0;
}

int display_errno_end(int errno)
{
    switch (errno) {
        case 129:
            my_print_error("Key was rejected by service");
            break;
        case 130:
            my_print_error("Owner died");
            break;
        case 131:
            my_print_error("State not recoverable");
            break;
    }
    return 0;
}
