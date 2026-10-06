/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** parsing_buffer.c
*/

#include "lib.h"
#include "base.h"


unsigned long get_endian(unsigned long n)
{
    unsigned long res = 0;
    res |= (n & 0x000000FF) << 24u;
    res |= (n & 0x0000FF00) << 8u;
    res |= (n & 0x00FF0000) >> 8u;
    res |= (n & 0xFF000000) >> 24u;
    return res;
}

int parse_file_name(header_t *header, char *buffer, int len)
{
    (void)header;
    int name_pos = 5;
    char *name = &buffer[name_pos];

    if (name == NULL) {
        my_putstr_error("Error: Malloc failed\n");
        return 1;
    }
    if (name_pos + my_strnlen(name, len - name_pos) > len - 4
    || my_strnlen(name, len - name_pos) > PROG_NAME_LENGTH
    || !my_strnlen(name, len - name_pos)) {
        my_putstr_error("Error: Invalid name\n");
        return 2;
    }
    return 0;
}

int parse_file_comment(header_t *header, char *buffer, int len)
{
    (void)header;
    int comment_pos = 140;
    char *comment = &buffer[comment_pos];

    if (comment == NULL) {
        my_putstr_error("Error: Malloc failed\n");
        return 1;
    }
    if (comment_pos + my_strnlen(comment, len - comment_pos) > len - 4
    || my_strnlen(comment, len - comment_pos) > COMMENT_LENGTH
    || !my_strnlen(comment, len - comment_pos)) {
        my_putstr_error("Error: Invalid comment\n");
        return 2;
    }
    return 0;
}

int parse_content_file(header_t *header, char *buffer, int len)
{
    (void)header;
    (void)buffer;
    if (2192 >= len - 4) {
        my_putstr_error("Error: Missing content\n");
        return 1;
    }
    return 0;
}

int parse_file(char *buffer, int len)
{
    if (len < 2196) {
        my_putstr_error("Error: File is too small\n");
        return 1;
    } else if (get_endian(*(__uint32_t *)buffer)
    != (unsigned long long)COREWAR_EXEC_MAGIC) {
        my_putstr_error("Error: Invalid magic number\n");
        return 2;
    }
    if (parse_file_name((header_t *)buffer, buffer, len))
        return 3;
    if (parse_file_comment((header_t *)buffer, buffer, len))
        return 4;
    if (parse_content_file((header_t *)buffer, buffer, len))
        return 5;
    return 0;
}
