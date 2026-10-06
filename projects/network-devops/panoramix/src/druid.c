/*
** EPITECH PROJECT, 2024
** druid.c
** File description:
** druid functions
*/

#include "../include/panoramix.h"

void *druid_thread(void *arg)
{
    druid_t *druid = (druid_t *)arg;

    printf("Druid: I'm ready... but sleepy...\n");
    while (druid->nb_refills > 0) {
        sem_wait(&druid->pot_sem);
        druid->nb_refills--;
        druid->nb_potions = druid->pot_size;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! " \
        "Beware I can only make %d more refills " \
        "after this one.\n", druid->nb_refills);
        if (druid->nb_refills == 0) {
            sem_post(&druid->sem2);
            printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
            break;
        }
        sem_post(&druid->sem2);
    }
    pthread_exit(NULL);
}

int init_druid(panoramix_t p)
{
    pthread_t druid_thread_id;
    druid_t *druid = malloc(sizeof(druid_t));

    if (druid == NULL)
        return 1;
    druid->pot_size = p.pot_size;
    druid->nb_refills = p.nb_refills;
    druid->nb_potions = p.pot_size;
    if (sem_init(&druid->pot_sem, 0, 0))
        return 1;
    if (sem_init(&druid->sem2, 0, 0))
        return 2;
    if (pthread_mutex_init(&druid->pot_mutex, NULL))
        return 3;
    if (pthread_create(&druid_thread_id, NULL, druid_thread, druid))
        return 4;
    return init_villager(p, druid);
}
