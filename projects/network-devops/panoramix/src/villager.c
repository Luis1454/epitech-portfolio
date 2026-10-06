/*
** EPITECH PROJECT, 2024
** villager.c
** File description:
** villager functions
*/


#include "../include/panoramix.h"

void *villager_thread(void *v)
{
    printf("Villager %d: Going into battle!\n", ((villager_t *)v)->id);
    while (((villager_t *)v)->nb_fights > 0) {
        pthread_mutex_lock(&((villager_t *)v)->druid->pot_mutex);
        printf("Villager %d: I need a drink... I see %d servings left.\n",
            ((villager_t *)v)->id, ((villager_t *)v)->druid->nb_potions);
        if (((villager_t *)v)->druid->nb_potions == 0) {
            printf("Villager %d: Hey Pano wake up! We need more potion.\n",
                ((villager_t *)v)->id);
            sem_post(&((villager_t *)v)->druid->pot_sem);
            sem_wait(&((villager_t *)v)->druid->sem2);
        }
        ((villager_t *)v)->druid->nb_potions--;
        pthread_mutex_unlock(&((villager_t *)v)->druid->pot_mutex);
        ((villager_t *)v)->nb_fights--;
        printf("Villager %d: Take that roman scum! Only %d left.\n",
            ((villager_t *)v)->id, ((villager_t *)v)->nb_fights);
    }
    printf("Villager %d: I'm going to sleep now.\n", ((villager_t *)v)->id);
    pthread_exit(NULL);
}

int init_villager(panoramix_t p, druid_t *druid)
{
    pthread_t *vthreads = malloc(sizeof(pthread_t) * p.nb_villagers);

    if (vthreads == NULL)
        return 10;
    for (int i = 0; i < p.nb_villagers; i++) {
        p.villagers[i].id = i;
        p.villagers[i].nb_fights = p.nb_fights;
        p.villagers[i].druid = druid;
        if (pthread_create(&vthreads[i], NULL,
            villager_thread, &p.villagers[i])) {
            safe_free(vthreads);
            safe_free(druid);
            return 11;
        }
    }
    for (int i = 0; i < p.nb_villagers; i++)
        pthread_join(vthreads[i], NULL);
    safe_free(vthreads);
    safe_free(druid);
    return 0;
}
