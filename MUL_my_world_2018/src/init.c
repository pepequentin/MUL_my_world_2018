/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/my.h"

void inittwo(world_t *world)
{
    world->color.r = 191;
    world->color.g = 191;
    world->color.b = 191;
    world->color.a = 1;
    world->bouton_on = 0;
    world->temp = 0;
}

void init(world_t *world)
{
    world->rotation = 45;
    world->i = 0;
    world->colored_or_not = 0;
    world->center_x = 360;
    world->center_y = 640;
    world->radius = 10;
    world->angle_x = 0;
    world->angle_y = 0;
    world->angle_z = 1.989998;
    world->f = 3665;
    world->perspective = 34.5;
    world->mouse_x = 0;
    world->mouse_y = 0;
    world->click = 0;
    world->clicktoolbar = 0;
    world->haut = 0;
    world->bas = 0;
    inittwo(world);
    create_texture(world);
}

const char *icon[3] = {
    "./asset/grass.png",
    "./asset/terre-compost.png",
    "./asset/cobble.png"
};