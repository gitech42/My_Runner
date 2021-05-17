/*
** EPITECH PROJECT, 2021
** function & struct
** File description:
** 
*/

#ifndef MY_H
#define MY_H

#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/Window/Keyboard.h>


typedef struct display {
    int dep;
    int jump;
    sfTexture *my_texture;
    sfSprite *my_sprite;
    sfTexture *disp1;
    sfTexture *disp2;
    sfTexture *disp3;
    sfTexture *disp4;
    sfSprite *p1;
    sfSprite *p2;
    sfSprite *p3;
    sfSprite *p4;
    sfTexture *back;
    sfTexture *bback;
    sfSprite *b1;
    sfSprite *bb1;
    sfVector2f p_disp1;
    sfVector2f p_disp2;
    sfVector2f p_disp3;
    sfVector2f p_disp4;
    sfVector2f p_back;
    sfVector2f p_bback;
    sfVector2f p_my_sprite;
    sfVector2f scale1;
    sfVector2f scaleb;
    int time2;
    sfTime time;
    sfIntRect rec;
    sfSprite *my_body;
    sfTexture *body;
    sfVector2f p_body;
    sfVector2f body_scale;
    sfVector2f p_body2;
    sfVector2f p_body3;
    sfVector2f p_body4;
    sfSprite *my_body2;
    sfSprite *my_body3;
    sfSprite *my_body4;
    sfTexture *body2;
    sfTexture *body3;
    sfTexture *body4;
    sfFont *font;
    sfText *text;
    float score;
    sfClock *sclock;
    sfTime stime;
    float sec;
    sfVector2f p_nuage;
    sfVector2f p_nuage2;
    sfVector2f p_nuage3;
    sfVector2f p_nuage4;
    sfSprite *nuage;
    sfSprite *nuage2;
    sfSprite *nuage3;
    sfSprite *nuage4;
    sfTexture *tnuage;
    sfTexture *tnuage2;
    sfTexture *tnuage3;
    sfTexture *tnuage4;
    sfText *over;
    sfVector2f scale_nuage;
    sfVector2f inv;
} display_t;

display_t init_sprite(display_t p);
void my_runner(display_t p);
char *my_itoa(int nb);
void display_sprite(display_t p, sfRenderWindow *window);
display_t init_positions(display_t p);
int my_strcmp(char const *s1, char const *s2);
void one_sprite(display_t p, sfClock *chrono);
display_t action(display_t p);
display_t action2(display_t p);
display_t space(display_t p);
display_t score(display_t p, sfRenderWindow *window);
int touch(display_t p, sfRenderWindow *window);
int  my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);
display_t sound(display_t p);
display_t run_infinite(display_t p);
void hoption(void);
#endif 
