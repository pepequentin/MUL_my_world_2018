/*
** EPITECH PROJECT, 2018
** window
** File description:
** window
*/

#include "../include/my.h"

void boutonsprite(sfRenderWindow *w, world_t *world)
{
    sfTexture *map_tt;
    if (world->colored_or_not == 0)
        map_tt = sfTexture_createFromFile("./asset/yellowb.png", NULL);
    if (world->colored_or_not == 1)
        map_tt = sfTexture_createFromFile("./asset/redb.png", NULL);
    if (world->colored_or_not == 2)
        map_tt = sfTexture_createFromFile("./asset/greenb.png", NULL);
    sfSprite *map_s = sfSprite_create();
    sfVector2f centre = {105, 560};
    sfSprite_setPosition(map_s, centre);
    sfSprite_setTexture(map_s, map_tt, sfTrue);
    sfRenderWindow_drawSprite(w, map_s, NULL);
    sfTexture_destroy(map_tt);
    sfSprite_destroy(map_s);
}

void check_color(world_t *w)
{
    if (w->mouse_x_toolbar-35<130 && \
        w->mouse_y_toolbar-38.5<600.5 && \
        w->mouse_x_toolbar+35>130 && \
        w->mouse_y_toolbar+38.5>600.5 && w->clicktoolbar > 0) {
        w->colored_or_not++;
        w->clicktoolbar = 0;
    }
    if (w->colored_or_not == 3)
        w->colored_or_not = 0;
}

void boutoncolor(world_t *w, sfRenderWindow *window)
{
    check_color(w);
    boutonsprite(window, w);
}