/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** all the functions
*/

#include <stdarg.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <stddef.h>
#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <math.h>

#include <stdio.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/System/Vector3.h>
#include <stdlib.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System.h>
#include <SFML/System/Vector2.h>


#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

#define MAP_X 10
#define MAP_Y 10
#define MAP_Z 1

#pragma once

typedef struct world_s {
    sfRenderWindow *window;
    sfRenderStates **states;
    float mouse_x_toolbar;
    float mouse_y_toolbar;
    int rotation;
    int i;
    int radius;
    int temp;
    int a;
    float angle_x;
    float angle_y;
    float angle_z;
    int count_x;
    int count_y;
    int count_z;
    int f;
    float perspective;
    int center_x;
    int center_y;
    float mouse_x;
    float mouse_y;
    float ***twodmap;
    int click;
    sfEvent event;
    int clicktoolbar;
    int haut;
    int bas;
    sfColor color;
    int nbr_of_lac;
    int nbr_of_mountain;
    int bouton_on;
    int colored_or_not;
    int three_d;
    int two_d;
    int one_d;
} world_t;

extern const char *icon[3];

void my_secondwindow(world_t *w, sfRenderWindow *toolbar);
void my_event(sfRenderWindow *w, world_t *world);
int bootstrap(sfRenderWindow *w);
void create_2d_map(world_t *world);
void my_alloc(world_t *world);
void init(world_t *world);
int before_circle(sfRenderWindow *window, sfVector2f **twodmap);

void circle(sfVector2f coord, sfRenderWindow *w, world_t *world);

void create_texture(world_t *w);

void vertex_y(sfRenderWindow *window, sfVector2f ***tw, world_t *w);
void vertex_x(sfRenderWindow *window, sfVector2f ***tw, world_t *w);
void vertex_z(sfRenderWindow *window, sfVector2f ***tw, world_t *w);
void allvertex(sfVector2f ***twodmap, world_t *world);

void body_color(sfVector2f ***twodmap, world_t *world);
void draw_triangle(world_t *, sfVector2f , sfVector2f , sfVector2f , sfColor);
sfColor choose_color(float lvl_grnd_a, float lvl_grnd_b, float lvl_grnd_c);
sfVector2f middle_point(sfVector2f point_a, sfVector2f point_b);

void check_mouse(sfVector2f ***hard, world_t *world);
void event_clicktoolbar(world_t *world);
void arrow_down(sfRenderWindow *w, world_t *world);
void arrow_hight(sfRenderWindow *w, world_t *world);

void tableau(sfRenderWindow *w);
void resetbouton_on(sfRenderWindow *w, world_t *world);
void resetbouton(world_t *w);
void allrotation(world_t *w);
void option(void);
void boutoncolor(world_t *w, sfRenderWindow *window);

void lapsu1(sfVector2f ***map, world_t *w, int i, int k);
void lapsu2(sfVector2f ***map, world_t *w, int i, int k);
void lapsu3(sfVector2f ***map, world_t *w, int i, int k);
void lapsu4(sfVector2f ***map, world_t *w, int i, int k);