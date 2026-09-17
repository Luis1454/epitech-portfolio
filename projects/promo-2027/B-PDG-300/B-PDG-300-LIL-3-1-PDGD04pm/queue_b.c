/*
** EPITECH PROJECT, 2024
** queue_b.c
** File description:
** day 04 PM
*/

#include <stdlib.h>
#include "queue.h"

void queue_clear(queue_t **queue_ptr)
{
    queue_t *tmp = *queue_ptr;

    while (tmp) {
        tmp = tmp->next;
        free(*queue_ptr);
        *queue_ptr = tmp;
    }
}

void *queue_front(queue_t *queue)
{
    return queue->value;
}
