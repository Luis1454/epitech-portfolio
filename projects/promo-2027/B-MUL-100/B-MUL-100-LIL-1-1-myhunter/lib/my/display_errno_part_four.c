/*
** EPITECH PROJECT, 2022
** display_errno_part_four.c
** File description:
** get errno msg
*/

int my_print_error(char const *str);

int display_errno_p(int errno)
{
    switch (errno) {
        case 79:
            my_print_error("Can not access a needed shared library");
            break;
        case 80:
            my_print_error("Accessing a corrupted shared library");
            break;
        case 81:
            my_print_error(".lib section in a.out corrupted");
            break;
        case 82:
            my_print_error("Attempting to link in too many shared libraries");
            break;
        case 83:
            my_print_error("Cannot exec a shared library directly");
            break;
    }
    return 0;
}

int display_errno_q(int errno)
{
    switch (errno) {
        case 84:
            my_print_error("Illegal byte sequence");
            break;
        case 85:
            my_print_error("Interrupted system call should be restarted");
            break;
        case 86:
            my_print_error("Streams pipe error");
            break;
        case 87:
            my_print_error("Too many users");
            break;
        case 88:
            my_print_error("Socket operation on non-socket");
            break;
    }
    return 0;
}

int display_errno_r(int errno)
{
    switch (errno) {
        case 89:
            my_print_error("Destination address required");
            break;
        case 90:
            my_print_error("Message too long");
            break;
        case 91:
            my_print_error("Protocol wrong type for socket");
            break;
        case 92:
            my_print_error("Protocol not available");
            break;
        case 93:
            my_print_error("Protocol not supported");
            break;
    }
    return 0;
}

int display_errno_s(int errno)
{
    switch (errno) {
        case 94:
            my_print_error("Socket type not supported");
            break;
        case 95:
            my_print_error("Operation not supported on transport endpoint");
            break;
        case 96:
            my_print_error("Protocol family not supported");
            break;
        case 97:
            my_print_error("Address family not supported by protocol");
            break;
        case 98:
            my_print_error("Address already in use");
            break;
    }
    return 0;
}

int display_errno_t(int errno)
{
    switch (errno) {
        case 99:
            my_print_error("Cannot assign requested address");
            break;
        case 100:
            my_print_error("Network is down");
            break;
        case 101:
            my_print_error("Network is unreachable");
            break;
        case 102:
            my_print_error("Network dropped connection because of reset");
            break;
        case 103:
            my_print_error("Software caused connection abort");
            break;
    }
    return 0;
}
