/*
** EPITECH PROJECT, 2018
** allscreensaver
** File description:
** screen
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "../include/my.h"
#include "../include/struct.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}

void option(void)
{
    my_putstr("My_world with a toolbar\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_world\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("  -h                print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" UpKey/DownKey/RightKey/LeftKey = move in the map\n");
    my_putstr(" MouseWheelScroll = zoom\n\n");
    my_putstr("KEY BOARD INTERACTIONS\n");
    my_putstr(" Space bar = speed quit\n");
    my_putstr(" Zoom = T/G on the heyboard\n");
    my_putstr(" Rotation in x = I/K on the heyboard\n");
    my_putstr(" Rotation in y = O/L on the heyboard\n");
    my_putstr(" Rotation in z = P/M on the heyboard\n\n");
    my_putstr("TOOLBAR INTERACTIONS\n");
    my_putstr(" You can use the toolbar to do all the\n");
    my_putstr(" rotations and terrain editing as well as a map reset\n\n");
    my_putstr("Thanks!\n");
}

char *cleanstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = '\0';
    return (str);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}