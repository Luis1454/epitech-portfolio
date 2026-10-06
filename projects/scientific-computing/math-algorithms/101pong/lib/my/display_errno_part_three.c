/*
** EPITECH PROJECT, 2022
** display_errno_part_three.c
** File description:
** get errno msg
*/

int my_print_error(char const *str);

int display_errno_k(int errno)
{
    switch (errno) {
        case 53:
            my_print_error("Invalid request descriptor");
            break;
        case 54:
            my_print_error("Exchange full");
            break;
        case 55:
            my_print_error("No anode");
            break;
        case 56:
            my_print_error("Invalid request code");
            break;
        case 57:
            my_print_error("Invalid slot");
            break;
    }
    return 0;
}

int display_errno_l(int errno)
{
    switch (errno) {
        case 59:
            my_print_error("Bad font file format");
            break;
        case 60:
            my_print_error("Device not a stream");
            break;
        case 61:
            my_print_error("No data available");
            break;
        case 62:
            my_print_error("Timer expired");
            break;
        case 63:
            my_print_error("Out of streams resources");
            break;
    }
    return 0;
}

int display_errno_m(int errno)
{
    switch (errno) {
        case 64:
            my_print_error("Machine is not on the network");
            break;
        case 65:
            my_print_error("Package not installed");
            break;
        case 66:
            my_print_error("Object is remote");
            break;
        case 67:
            my_print_error("Link has been severed");
            break;
        case 68:
            my_print_error("Advertise error");
            break;
    }
    return 0;
}

int display_errno_n(int errno)
{
    switch (errno) {
        case 69:
            my_print_error("Srmount error");
            break;
        case 70:
            my_print_error("Communication error on send");
            break;
        case 71:
            my_print_error("Protocol error");
            break;
        case 72:
            my_print_error("Multihop attempted");
            break;
        case 73:
            my_print_error("RFS specific error");
            break;
    }
    return 0;
}

int display_errno_o(int errno)
{
    switch (errno) {
        case 74:
            my_print_error("Not a data message");
            break;
        case 75:
            my_print_error("Value too large for defined data type");
            break;
        case 76:
            my_print_error("Name not unique on network");
            break;
        case 77:
            my_print_error("File descriptor in bad state");
            break;
        case 78:
            my_print_error("Remote address changed");
            break;
    }
    return 0;
}
