/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/my.h"

void resetbouton_on(sfRenderWindow *w, world_t *world)
{
    sfTexture *map_tt;
    if (world->bouton_on == 1) {
        map_tt = sfTexture_createFromFile("./asset/on.png", NULL);
        world->temp++;
    }
    else
        map_tt = sfTexture_createFromFile("./asset/reset.png", NULL);
    sfSprite *map_s = sfSprite_create();
    sfVector2f centre = {150, 800};
    sfSprite_setPosition(map_s, centre);
    sfSprite_setTexture(map_s, map_tt, sfTrue);
    sfRenderWindow_drawSprite(w, map_s, NULL);
    sfTexture_destroy(map_tt);
    sfSprite_destroy(map_s);
    if (world->temp > 40) {
        world->bouton_on = 0;
        world->temp = 0;
    }
}

void fast(int i, int j, world_t *w)
{
    for (int k = 0; k < MAP_X; k++)
        w->twodmap[i][j][k] = 0;
}

void goresetthemap(world_t *w)
{
    for (int i = 0; i < MAP_Z; i++)
        for (int j = 0; j < MAP_Y; j++)
            fast(i, j, w);
    w->angle_x = 0;
    w->angle_y = 0;
    w->angle_z = 1.98;
    w->f = 3665;
    w->center_x = 360;
    w->center_y = 640;
    w->mouse_x = -1000;
}

void resetbouton(world_t *w)
{
    if (w->mouse_x_toolbar-38.5<220 && \
        w->mouse_y_toolbar-20.5<835 && \
        w->mouse_x_toolbar+38.5>220 && \
        w->mouse_y_toolbar+20.5>835 && w->clicktoolbar > 0) {
        w->bouton_on = 1;
        w->clicktoolbar = 0;
        goresetthemap(w);
    }
}