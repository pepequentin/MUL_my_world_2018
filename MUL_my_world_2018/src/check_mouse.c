/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "../include/my.h"
#include "../include/struct.h"
#include <stdio.h>

void check_tool(world_t *w)
{
    if (w->bas == 1 && w->haut == 1)
        w->click = 0;
    if (w->bas == 0 && w->haut == 0)
        w->click = 0;
}

void check_mouse(sfVector2f ***hard, world_t *w)
{
    check_tool(w);
    if (w->mouse_x + 40 > hard[w->count_z][w->count_y][w->count_x].x && \
        w->mouse_x - 40 < hard[w->count_z][w->count_y][w->count_x].x && \
        w->mouse_y + 40 > hard[w->count_z][w->count_y][w->count_x].y && \
        w->mouse_y - 40 < hard[w->count_z][w->count_y][w->count_x].y && \
        w->click > 0 && w->haut == 1 && w->bas == 0) {
        w->twodmap[w->count_z][w->count_y][w->count_x] += 1;
        w->click = 0;
    }
    if (w->mouse_x + 40 > hard[w->count_z][w->count_y][w->count_x].x && \
        w->mouse_x - 40 < hard[w->count_z][w->count_y][w->count_x].x && \
        w->mouse_y + 40 > hard[w->count_z][w->count_y][w->count_x].y && \
        w->mouse_y - 40 < hard[w->count_z][w->count_y][w->count_x].y && \
        w->click > 0 && w->bas == 1 && w->haut == 0) {
        w->twodmap[w->count_z][w->count_y][w->count_x] -= 1;
        w->click = 0;
    }
}