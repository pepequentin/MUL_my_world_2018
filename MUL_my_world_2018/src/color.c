/*
** EPITECH PROJECT, 2019
** My_world
** File description:
** color
*/

#include "../include/my.h"

int init_i(world_t *w)
{
    int a = w->twodmap[0][w->two_d][w->one_d];
    int b = w->twodmap[0][w->two_d + 1][w->one_d + 1];
    int c = w->twodmap[0][w->two_d + 1][w->one_d];
    int d = w->twodmap[0][w->two_d][w->one_d + 1];

    if ((a + b + c + d) < 0 && (a <= 0 || b <= 0 || c <= 0))
        return (1);
    if ((a + b + c + d) > 10 && (a >= 3 || b >= 3 || c >= 3 || d >= 3))
        return (2);
    return (0);
}

sfColor choose_color(float lvl_grnd_a, float lvl_grnd_b, float lvl_grnd_c)
{
    if (lvl_grnd_a == 0 && lvl_grnd_b == 0 && lvl_grnd_c == 0)
        return (sfGreen);
    else if (lvl_grnd_a == 1 && lvl_grnd_b == 1 && lvl_grnd_c == 1)
        return (sfYellow);
    else if ((lvl_grnd_a + lvl_grnd_b + lvl_grnd_c) < 0)
        return (sfRed);
    else
        return (sfBlue);
}

void create_texture(world_t *w)
{
    sfTexture *texture;

    w->states = malloc(sizeof(sfRenderStates *) * 3);
    for (int i = 0; i < 3; i++) {
        w->states[i] = malloc(sizeof(sfRenderStates));
        texture = sfTexture_createFromFile(icon[i], NULL);
        w->states[i]->shader = NULL;
        w->states[i]->blendMode = sfBlendAlpha;
        w->states[i]->texture = texture;
        w->states[i]->transform = sfTransform_Identity;
    }
}

void draw_triangle(world_t *w, sfVector2f a, sfVector2f b, sfVector2f c, sfColor g)
{
    int i = init_i(w);
    if (w->colored_or_not == 2)
        g = sfWhite;
    sfVertexArray *vert = sfVertexArray_create();
    sfVertex f = {.position = a, .texCoords = (sfVector2f){0, 0}, .color = g};
    sfVertex s = {.position = b, .texCoords = (sfVector2f){0, 32}, .color = g};
    sfVertex t = {.position = c, .texCoords = (sfVector2f){32, 0}, .color = g};
    sfVertexArray_append(vert, f);
    sfVertexArray_append(vert, s);
    sfVertexArray_append(vert, t);
    sfVertexArray_setPrimitiveType(vert, sfTrianglesStrip);
    if (w->colored_or_not == 1)
        sfRenderWindow_drawVertexArray(w->window, vert, NULL);
    else
        sfRenderWindow_drawVertexArray(w->window, vert, w->states[i]);
}


sfVector2f middle_point(sfVector2f point_a, sfVector2f point_b)
{
    sfVector2f new_point;

    new_point.x = (point_a.x + point_b.x) / 2;
    new_point.y = (point_a.y + point_b.y) / 2;
    return (new_point);
}
