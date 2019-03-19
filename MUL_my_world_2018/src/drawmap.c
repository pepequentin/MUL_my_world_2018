/*
** EPITECH PROJECT, 2019
** map
** File description:
** map
*/

#include "../include/my.h"

sfVector2f project_iso_point(int x, int y, int z, world_t *world)
{
    sfVector3f ddd;
    sfVector3f triple;
    sfVector2f dd;
    float b = world->angle_x;
    float a = world->angle_y;
    float c = world->angle_z;
    dd.x = (cos(a) * x) - (sin(a) * y);
    dd.y = (sin(a) * x) + (cos(a) * y);
    ddd.x = (cos(b) * dd.x) + (sin(b) * z);
    triple.z = (cos(b) * z) - (sin(b) * dd.x);
    ddd.y = (cos(c) * dd.y) - (sin(c) * triple.z);
    ddd.z = (sin(c) * dd.y) + (cos(c) * triple.z);
    dd.x = world->center_x + ((ddd.x * world->f) / (ddd.z + world->perspective));
    dd.y = world->center_y + ((ddd.y * world->f) / (ddd.z + world->perspective));
    if (ddd.z < -4.5)
        dd.y = -1;
    return (dd);
}

void drawmap(sfVector2f ***twodmap, world_t *world)
{
    for (world->count_z = 0; world->count_z < MAP_Z; world->count_z++)
        for (world->count_y = 0; world->count_y < MAP_Y; world->count_y++)
            allvertex(twodmap, world);
}

void create_2d_map(world_t *a)
{
    sfVector2f ***map2d = malloc(sizeof(sfVector2f**) * (MAP_Z));

    for (a->count_z = 0; a->count_z < MAP_Z; a->count_z++) {
        map2d[a->count_z] = malloc(sizeof(sfVector2f*) * (MAP_Y));
        for (a->count_y = 0; a->count_y < MAP_Y; a->count_y++) {
            map2d[a->count_z][a->count_y] = malloc(sizeof(sfVector2f) * (MAP_X));
            for (a->count_x = 0; a->count_x < MAP_X; a->count_x++)
                map2d[a->count_z][a->count_y][a->count_x] = project_iso_point(a->count_x, a->count_y, a->twodmap[a->count_z][a->count_y][a->count_x], a);
        }
    }
    drawmap(map2d, a);
}