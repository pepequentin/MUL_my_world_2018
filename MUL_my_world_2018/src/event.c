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

void event_angle(world_t *world)
{
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyM)
        world->angle_y -= 0.01;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyP)
        world->angle_y += 0.01;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyI)
        world->angle_x += 0.01;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyK)
        world->angle_x -= 0.01;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyO)
        world->angle_z += 0.01;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyL)
        world->angle_z -= 0.01;
}

void event_center(world_t *world)
{
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyUp)
        world->center_y -= 10;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyDown)
        world->center_y += 10;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyRight)
        world->center_x += 10;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyLeft)
        world->center_x -= 10;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyPageUp) {
        world->center_y -= 10;
        world->center_x -= 10;
    }
}

void event_movement(world_t *world)
{
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyT)
        world->f += MAP_X;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyG)
        world->f -= MAP_X;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyE)
        world->perspective += 0.01;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyD)
        world->perspective -= 0.01;
    if (world->event.type == sfEvtKeyPressed && \
        world->event.key.code == sfKeyPageDown) {
        world->center_x += 10;
        world->center_y += 10;
    }
}

void event_click(world_t *world)
{
    if (world->event.type == sfEvtMouseButtonPressed && \
        world->event.mouseButton.button == sfMouseLeft) {
        world->mouse_x = world->event.mouseButton.x;
        world->mouse_y = world->event.mouseButton.y;
        world->click = 1;
    }
    if (world->event.mouseWheelScroll.delta != 0)
        world->f += world->event.mouseWheelScroll.delta * 10;
}

void my_event(sfRenderWindow *w, world_t *world)
{
    while (sfRenderWindow_pollEvent(w, &world->event)) {
        if (world->event.type == sfEvtClosed)
            sfRenderWindow_close(w);
        event_angle(world);
        event_movement(world);
        event_center(world);
        event_click(world);
        if (world->event.type == sfEvtKeyPressed && \
            world->event.key.code == sfKeySpace)
            sfRenderWindow_close(w);
    }
}