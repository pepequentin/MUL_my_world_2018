/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "./include/my.h"

int my_window(world_t *w)
{
    sfVideoMode mode = {1530, 1080, 32};
    sfVideoMode modetwo = {290, 1080, 32};
    sfRenderWindow *toolbar;
    toolbar = sfRenderWindow_create(modetwo, "bar", sfResize | sfClose, NULL);
    w->window = sfRenderWindow_create(mode, "map", sfResize | sfClose, NULL);
    sfRenderWindow_setPosition(toolbar, (sfVector2i){0, 1080});
    sfRenderWindow_setPosition(w->window, (sfVector2i){290, 1080});
    sfRenderWindow_setFramerateLimit(w->window, 60);
    while (sfRenderWindow_isOpen(w->window)) {
        sfRenderWindow_clear(w->window, sfBlack);
        sfRenderWindow_clear(toolbar, w->color);
        my_secondwindow(w, toolbar);
        create_2d_map(w);
        sfRenderWindow_display(w->window);
        sfRenderWindow_display(toolbar);
        my_event(w->window, w);
    }
    sfRenderWindow_destroy(w->window);
    sfRenderWindow_destroy(toolbar);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        option();
        return (0);
    }
    world_t *w = malloc(sizeof(world_t));
    init(w);
    my_alloc(w);
    my_window(w);
    return (0);
}
