/*
** EPITECH PROJECT, 2024
** panoramix.h
** File description:
** panoramix
*/

#ifndef PANORAMIX_H_
    #define PANORAMIX_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>
    #include <semaphore.h>

typedef struct druid_s {
    int pot_size;
    int nb_refills;
    int nb_potions;
    sem_t pot_sem;
    sem_t sem2;
    pthread_mutex_t pot_mutex;
} druid_t;

typedef struct villager_s {
    int id;
    int nb_fights;
    druid_t *druid;
    pthread_mutex_t v_mutex;
} villager_t;

typedef struct panoramix_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
    villager_t *villagers;
    int status;
} panoramix_t;

void safe_free(void *ptr);

int parser(panoramix_t *p, int argc, char **argv);

int init_druid(panoramix_t p);

int init_villager(panoramix_t p, druid_t *druid);

#endif /* !PANORAMIX_H_ */
