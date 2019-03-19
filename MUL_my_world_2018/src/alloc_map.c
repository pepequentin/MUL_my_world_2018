/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/my.h"

void second(int i, int j, world_t *world)
{
    for (int k = 0; k < MAP_X; k++) {
        if (k == 0 || j == 0 || k == MAP_X - 1 || j == MAP_Y - 1)
            world->twodmap[i][j][k] = 0;
        else
            world->twodmap[i][j][k] = 1;
    }
}

void my_alloc(world_t *world)
{
    world->nbr_of_lac = MAP_X * MAP_Y / 90;
    world->nbr_of_mountain = MAP_X* MAP_Y / 40;
    world->twodmap = malloc(sizeof(float **) * MAP_Z);
    for (int i = 0; i < MAP_Z; i++) {
        world->twodmap[i] = malloc(sizeof(float *) * MAP_Y);
        for (int j = 0; j < MAP_Y; j++) {
            world->twodmap[i][j] = malloc(sizeof(float) * MAP_X);
            second(i, j, world);
        }
    }
}