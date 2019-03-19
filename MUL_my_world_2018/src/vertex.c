/*
** EPITECH PROJECT, 2019
** map
** File description:
** map
*/
#include "../include/my.h"

sfVertexArray *create_line(sfVector2f *p1, sfVector2f *p2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *p1, .color = sfWhite};
    sfVertex vertex2 = {.position = *p2, .color = sfWhite};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

void vertex_x(sfRenderWindow *window, sfVector2f ***tw, world_t *w)
{
    int x = w->count_x;
    int y = w->count_y;
    int z = w->count_z;
    if (tw[z][y][x].y > 0 && tw[z][y][x + 1].y > 0) {
    sfVertexArray *line = create_line((&tw[z][y][x]), (&tw[z][y][x + 1]));
    sfRenderWindow_drawVertexArray(window, line, NULL);
    sfVertexArray_destroy(line);
    }
}

void vertex_y(sfRenderWindow *window, sfVector2f ***tw, world_t *w)
{
    int x = w->count_x;
    int y = w->count_y;
    int z = w->count_z;
    if (tw[z][y][x].y > 0 && tw[z][y + 1][x].y > 0) {
    sfVertexArray *line = create_line((&tw[z][y][x]), (&tw[z][y + 1][x]));
    sfRenderWindow_drawVertexArray(window, line, NULL);
    sfVertexArray_destroy(line);
    }
}

void vertex_z(sfRenderWindow *window, sfVector2f ***tw, world_t *w)
{
    int x = w->count_x;
    int y = w->count_y;
    int z = w->count_z;
    if (tw[z][y][x].y > 0 && tw[z + 1][y][x].y > 0) {
    sfVertexArray *line = create_line((&tw[z][y][x]), (&tw[z + 1][y][x]));
    sfRenderWindow_drawVertexArray(window, line, NULL);
    sfVertexArray_destroy(line);
    }
}

void allvertex(sfVector2f ***twodmap, world_t *world)
{
    for (world->count_x = 0; world->count_x < MAP_X; world->count_x++) {
        check_mouse(twodmap, world);
        if (world->count_z < MAP_Z - 1)
            vertex_z(world->window, twodmap, world);
        if (world->count_x == MAP_X - 1 && world->count_y == MAP_Y - 1)
            break;
        if (world->count_y == MAP_Y - 1)
            vertex_x(world->window, twodmap, world);
        else if (world->count_x == MAP_X - 1)
            vertex_y(world->window, twodmap, world);
        else {
            vertex_x(world->window, twodmap, world);
            vertex_y(world->window, twodmap, world);
        }
    }
    if (world->colored_or_not != 0)
        body_color(twodmap, world);
}