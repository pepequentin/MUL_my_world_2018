/*
** EPITECH PROJECT, 2019
** map
** File description:
** map
*/
#include "../include/my.h"

void rotationinx(world_t *w)
{
    if (w->mouse_x_toolbar-25<65 && \
        w->mouse_y_toolbar-28.5<390.5 && \
        w->mouse_x_toolbar+15>65 && \
        w->mouse_y_toolbar+28.5>390.5 && w->clicktoolbar > 0) {
        w->angle_x += 0.02;
        w->clicktoolbar = 0;
    }
    if (w->mouse_x_toolbar-25<65 && \
        w->mouse_y_toolbar-28.5<455.5 && \
        w->mouse_x_toolbar+15>65 && \
        w->mouse_y_toolbar+28.5>455.5 && w->clicktoolbar > 0) {
        w->angle_x -= 0.02;
        w->clicktoolbar = 0;
    }
}

void rotationiny(world_t *w)
{
    if (w->mouse_x_toolbar-25<140 && \
        w->mouse_y_toolbar-38.5<390.5 && \
        w->mouse_x_toolbar+15>140 && \
        w->mouse_y_toolbar+28.5>390.5 && w->clicktoolbar > 0) {
        w->angle_y += 0.02;
        w->clicktoolbar = 0;
    }
    if (w->mouse_x_toolbar-25<140 && \
        w->mouse_y_toolbar-38.5<455.5 && \
        w->mouse_x_toolbar+15>140 && \
        w->mouse_y_toolbar+28.5>455.5 && w->clicktoolbar > 0) {
        w->angle_y -= 0.02;
        w->clicktoolbar = 0;
    }
}

void rotationinz(world_t *w)
{
    if (w->mouse_x_toolbar-25<210 && \
        w->mouse_y_toolbar-38.5<390.5 && \
        w->mouse_x_toolbar+15>210 && \
        w->mouse_y_toolbar+28.5>390.5 && w->clicktoolbar > 0) {
        w->angle_z += 0.02;
        w->clicktoolbar = 0;
    }
    if (w->mouse_x_toolbar-25<210 && \
        w->mouse_y_toolbar-38.5<455.5 && \
        w->mouse_x_toolbar+15>210 && \
        w->mouse_y_toolbar+28.5>455.5 && w->clicktoolbar > 0) {
        w->angle_z -= 0.02;
        w->clicktoolbar = 0;
    }
}

void allrotation(world_t *w)
{
    rotationinx(w);
    rotationiny(w);
    rotationinz(w);
}