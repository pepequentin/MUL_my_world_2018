/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/my.h"

void intab(int i, int j, int k, world_t *w)
{
    w->three_d = i;
    w->two_d = j;
    w->one_d = k;
}

void lapsu1(sfVector2f ***m, world_t *w, int i, int k)
{
    sfVector2f coord;
    sfVector2f coord2;
    sfVector2f coord3;

    for (int j = MAP_Y - 2; j >= 0; j--) {
        intab(i, j, k, w);
        coord = middle_point(m[i][j][k], m[i][j + 1][k + 1]);
        coord2 = middle_point(m[i][j][k + 1], m[i][j + 1][k]);
        coord3.x = (coord.x + coord2.x) / 2;
        coord3.y = (coord.y + coord2.y) / 2;
        draw_triangle(w, m[i][j + 1][k + 1], coord3, m[i][j + 1][k], sfGreen);
        draw_triangle(w, m[i][j + 1][k + 1], m[i][j][k + 1], coord3, sfYellow);
        draw_triangle(w, m[i][j][k], m[i][j][k + 1], coord3, sfBlue);
        draw_triangle(w, m[i][j][k], coord3, m[i][j + 1][k], sfRed);
    }
}

void lapsu2(sfVector2f ***m, world_t *w, int i, int j)
{
    sfVector2f coord;
    sfVector2f coord2;
    sfVector2f coord3;

    for (int k = 0; k + 1 < MAP_X; k++) {
        intab(i, j, k, w);
        coord = middle_point(m[i][j][k], m[i][j + 1][k + 1]);
        coord2 = middle_point(m[i][j][k + 1], m[i][j + 1][k]);
        coord3.x = (coord.x + coord2.x) / 2;
        coord3.y = (coord.y + coord2.y) / 2;
        draw_triangle(w, m[i][j + 1][k + 1], coord3, m[i][j + 1][k], sfGreen);
        draw_triangle(w, m[i][j + 1][k + 1], m[i][j][k + 1], coord3, sfYellow);
        draw_triangle(w, m[i][j][k], m[i][j][k + 1], coord3, sfBlue);
        draw_triangle(w, m[i][j][k], coord3, m[i][j + 1][k], sfRed);
    }
}

void lapsu3(sfVector2f ***m, world_t *w, int i, int k)
{
    sfVector2f coord;
    sfVector2f coord2;
    sfVector2f coord3;

    for (int j = 0; j + 1 < MAP_Y; j++) {
        intab(i, j, k, w);
        coord = middle_point(m[i][j][k], m[i][j + 1][k + 1]);
        coord2 = middle_point(m[i][j][k + 1], m[i][j + 1][k]);
        coord3.x = (coord.x + coord2.x) / 2;
        coord3.y = (coord.y + coord2.y) / 2;
        draw_triangle(w, m[i][j + 1][k + 1], coord3, m[i][j + 1][k], sfGreen);
        draw_triangle(w, m[i][j + 1][k + 1], m[i][j][k + 1], coord3, sfYellow);
        draw_triangle(w, m[i][j][k], m[i][j][k + 1], coord3, sfBlue);
        draw_triangle(w, m[i][j][k], coord3, m[i][j + 1][k], sfRed);
    }
}

void lapsu4(sfVector2f ***m, world_t *w, int i, int k)
{
    sfVector2f coord;
    sfVector2f coord2;
    sfVector2f coord3;

    for (int j = 0; j + 1 < MAP_Y; j++) {
        intab(i, k, j, w);
        coord = middle_point(m[i][j][k], m[i][j + 1][k + 1]);
        coord2 = middle_point(m[i][j][k + 1], m[i][j + 1][k]);
        coord3.x = (coord.x + coord2.x) / 2;
        coord3.y = (coord.y + coord2.y) / 2;
        draw_triangle(w, m[i][j][k], coord3, m[i][j + 1][k], sfGreen);
        draw_triangle(w, m[i][j][k], m[i][j][k + 1], coord3, sfYellow);
        draw_triangle(w, m[i][j + 1][k + 1], m[i][j][k + 1], coord3, sfBlue);
        draw_triangle(w, m[i][j + 1][k + 1], coord3, m[i][j + 1][k], sfRed);
    }
}