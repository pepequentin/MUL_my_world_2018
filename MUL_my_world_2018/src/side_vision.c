/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** vertex color
*/

#include "../include/my.h"

void triangled4(sfVector2f ***map, world_t *w)
{
    for (int i = 0; i < MAP_Z; i++) {
        for (int k = 0; k + 1 < MAP_X; k++) {
            lapsu4(map, w, i, k);
        }
    }
}

void face_of(sfVector2f ***map, world_t *w)
{
    for (int i = 0; i < MAP_Z; i++) {
        for (int j = MAP_Y - 2; j >= 0; j--) {
            lapsu2(map, w, i, j);
        }
    }
}

void back_of(sfVector2f ***map, world_t *w)
{
    for (int i = 0; i < MAP_Z; i++) {
        for (int k = MAP_X - 2; k >= 0; k--) {
            lapsu3(map, w, i, k);
        }
    }
}

void triangled6(sfVector2f ***map, world_t *w)
{
    for (int i = 0; i < MAP_Z; i++) {
        for (int k = MAP_X - 2; k >= 0; k--) {
            lapsu1(map, w, i, k);
        }
    }
}

void body_color(sfVector2f ***twodmap, world_t *world)
{
    if ((world->angle_y <= -0.0001 && world->angle_y > -1.52) || \
        (world->angle_y < 7 && world->angle_y > 4.73))
        face_of(twodmap, world);
    if ((world->angle_y >= -0.0002 && world->angle_y < 1.67) || \
        (world->angle_y < -4.64 && world->angle_y > -7))
        triangled6(twodmap, world);
    if ((world->angle_y > 3.16 && world->angle_y < 4.74) || \
        (world->angle_y > -3.07 && world->angle_y < -1.51))
        triangled4(twodmap, world);
    if ((world->angle_y > 1.66 && world->angle_y < 3.17) || \
        (world->angle_y > -4.65 && world->angle_y < -3.06))
        back_of(twodmap, world);
}