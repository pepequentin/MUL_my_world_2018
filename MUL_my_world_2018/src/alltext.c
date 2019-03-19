/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/my.h"

void tableau(sfRenderWindow *w)
{
    sfTexture *map_tt;
    map_tt = sfTexture_createFromFile("./asset/tableau.png", NULL);
    sfSprite *map_s = sfSprite_create();
    sfVector2f centre = {0, 50};
    sfSprite_setPosition(map_s, centre);
    sfSprite_setTexture(map_s, map_tt, sfTrue);
    sfRenderWindow_drawSprite(w, map_s, NULL);
    sfTexture_destroy(map_tt);
    sfSprite_destroy(map_s);
}
