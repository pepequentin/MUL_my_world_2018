/*
** EPITECH PROJECT, 2018
** window
** File description:
** window
*/

#include "../include/my.h"

void my_eventw(sfRenderWindow *w, world_t *world)
{
    while (sfRenderWindow_pollEvent(w, &world->event)) {
        if (world->event.type == sfEvtClosed)
            sfRenderWindow_close(w);
        if (world->event.type == sfEvtKeyPressed && \
            world->event.key.code == sfKeySpace)
            sfRenderWindow_close(w);
        if (world->event.type == sfEvtMouseButtonPressed && \
            world->event.mouseButton.button == sfMouseLeft) {
            world->mouse_x_toolbar = world->event.mouseButton.x;
            world->mouse_y_toolbar = world->event.mouseButton.y;
            world->clicktoolbar = 1;
        }
    }
}

void witchtranstwo(world_t *w)
{
    if (w->mouse_x_toolbar-35<80 && \
        w->mouse_y_toolbar-38.5<230.5 && \
        w->mouse_x_toolbar+35>80 && \
        w->mouse_y_toolbar+38.5>230.5 && w->clicktoolbar > 0 && \
        w->haut == 1) {
        w->haut = 0;
        w->clicktoolbar = 0;
    }
    if (w->mouse_x_toolbar-35<200 && \
        w->mouse_y_toolbar-48.5<230.5 && \
        w->mouse_x_toolbar+35>200 && \
        w->mouse_y_toolbar+48.5>230.5 && w->clicktoolbar > 0 && \
        w->bas == 1) {
        w->bas = 0;
        w->clicktoolbar = 0;
    }
}

void witchtrans(world_t *w)
{
    if (w->mouse_x_toolbar-35<80 && \
        w->mouse_y_toolbar-38.5<230.5 && \
        w->mouse_x_toolbar+35>80 && \
        w->mouse_y_toolbar+38.5>230.5 && w->clicktoolbar > 0 && \
        w->haut == 0) {
        w->haut = 1;
        w->clicktoolbar = 0;
    }
    if (w->mouse_x_toolbar-35<200 && \
        w->mouse_y_toolbar-38.5<230.5 && \
        w->mouse_x_toolbar+35>200 && \
        w->mouse_y_toolbar+38.5>230.5 && w->clicktoolbar > 0 && \
        w->bas == 0) {
        w->bas = 1;
        w->clicktoolbar = 0;
    }
    witchtranstwo(w);
}

void my_secondwindow(world_t *w, sfRenderWindow *toolbar)
{
    tableau(toolbar);
    my_eventw(toolbar, w);
    arrow_down(toolbar, w);
    allrotation(w);
    boutoncolor(w, toolbar);
    arrow_hight(toolbar, w);
    resetbouton_on(toolbar, w);
    witchtrans(w);
    resetbouton(w);
}