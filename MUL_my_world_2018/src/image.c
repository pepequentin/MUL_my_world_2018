/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/my.h"

void arrow_hight(sfRenderWindow *w, world_t *world)
{
    sfTexture *map_tt;
    if (world->haut == 1)
        map_tt = sfTexture_createFromFile("./asset/green_arrow.png", NULL);
    else
        map_tt = sfTexture_createFromFile("./asset/red_arrow.png", NULL);
    sfSprite *map_s = sfSprite_create();
    sfVector2f centre = {50, 200};
    sfSprite_setPosition(map_s, centre);
    sfSprite_setTexture(map_s, map_tt, sfTrue);
    sfRenderWindow_drawSprite(w, map_s, NULL);
    sfTexture_destroy(map_tt);
    sfSprite_destroy(map_s);
}

void arrow_down(sfRenderWindow *w, world_t *world)
{
    sfTexture *map_tt;
    if (world->bas == 1)
        map_tt = sfTexture_createFromFile("./asset/green_arrowneg.png", NULL);
    else
        map_tt = sfTexture_createFromFile("./asset/red_arrowneg.png", NULL);
    sfSprite *map_s = sfSprite_create();
    sfVector2f centre = {192, 205};
    sfSprite_setPosition(map_s, centre);
    sfSprite_setTexture(map_s, map_tt, sfTrue);
    sfRenderWindow_drawSprite(w, map_s, NULL);
    sfTexture_destroy(map_tt);
    sfSprite_destroy(map_s);
}