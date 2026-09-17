/*
** EPITECH PROJECT, 2024
** queue.c
** File description:
** day 04 PM
*/

#include <stdlib.h>
#include "queue.h"

unsigned int queue_get_size(queue_t *queue)
{
    unsigned int i = 0;

    for (queue_t *tmp = queue; tmp; tmp = tmp->next)
        i++;
    return i;
}

bool queue_is_empty(queue_t *queue)
{
    return queue == NULL;
}

bool queue_push(queue_t **queue_ptr, void *elem)
{
    queue_t *new = malloc(sizeof(queue_t));

    if (new == NULL)
        return false;
    new->value = elem;
    new->next = NULL;
    if (*queue_ptr == NULL) {
        *queue_ptr = new;
        return true;
    }
    for (queue_t *tmp = *queue_ptr; tmp; tmp = tmp->next) {
        if (tmp->next == NULL) {
            tmp->next = new;
            return true;
        }
    }
    return false;
}

bool queue_pop(queue_t **queue_ptr)
{
    queue_t *tmp = *queue_ptr;

    if (tmp == NULL)
        return false;
    *queue_ptr = tmp->next;
    free(tmp);
    return true;
}
