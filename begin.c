/*
** EPITECH PROJECT, 2021
** 
** File description:
** 
*/

#include "my.h"

display_t init_sprite(display_t p)
{
    p.nuage = sfSprite_create();
    p.tnuage = sfTexture_createFromFile("cloud.png", NULL);
    p.nuage2 = sfSprite_create();
    p.tnuage2 = sfTexture_createFromFile("cloud.png", NULL);
    p.nuage3 = sfSprite_create();
    p.tnuage3 = sfTexture_createFromFile("cloud.png", NULL);
    p.nuage4 = sfSprite_create();
    p.tnuage4 = sfTexture_createFromFile("cloud.png", NULL);
    p.sclock = sfClock_create();
    p.text = sfText_create();
    p.over = sfText_create();
    p.font = sfFont_createFromFile("NemoyLight.otf");
    p.body = sfTexture_createFromFile("dead_body.png", NULL);
    p.my_body = sfSprite_create();
    p.body2 = sfTexture_createFromFile("dead_body.png", NULL);
    p.my_body2 = sfSprite_create();
    p.body3 = sfTexture_createFromFile("dead_body.png", NULL);
    p.my_body3 = sfSprite_create();
    p.body4 = sfTexture_createFromFile("dead_body.png", NULL);
    p.my_body4 = sfSprite_create();
    p.my_texture = sfTexture_createFromFile("140553.png", NULL);
    p.my_sprite = sfSprite_create();
    p.disp1 = sfTexture_createFromFile("flappy-bird-1 (dragged).png", NULL);
    p.p1 = sfSprite_create();
    p.disp2 = sfTexture_createFromFile("flappy-bird-1 (dragged).png", NULL);
    p.p2 = sfSprite_create();
    p.disp3 = sfTexture_createFromFile("flappy-bird-1 (dragged).png", NULL);
    p.p3 = sfSprite_create();
    p.disp4 = sfTexture_createFromFile("flappy-bird-1 (dragged).png", NULL);
    p.p4 = sfSprite_create();
    p.back = sfTexture_createFromFile("map.png", NULL);
    p.b1 = sfSprite_create();
    p.bback = sfTexture_createFromFile("map.png", NULL);
    p.bb1 = sfSprite_create();

    sfSprite_setTexture(p.nuage, p.tnuage, sfTrue);
    sfSprite_setTexture(p.nuage2, p.tnuage2, sfTrue);
    sfSprite_setTexture(p.nuage3, p.tnuage3, sfTrue);
    sfSprite_setTexture(p.nuage4, p.tnuage4, sfTrue);
    sfSprite_setTexture(p.p1, p.disp1, sfTrue);
    sfSprite_setTexture(p.p2, p.disp2, sfTrue);
    sfSprite_setTexture(p.p3, p.disp3, sfTrue);
    sfSprite_setTexture(p.p4, p.disp4, sfTrue);
    sfSprite_setTexture(p.b1, p.back, sfTrue);
    sfSprite_setTexture(p.bb1, p.bback, sfTrue);
    sfSprite_setTexture(p.my_body, p.body, sfTrue);
    sfSprite_setTexture(p.my_body2, p.body2, sfTrue);
    sfSprite_setTexture(p.my_body3, p.body3, sfTrue);
    sfSprite_setTexture(p.my_body4, p.body4, sfTrue);
    sfSprite_setTexture(p.my_sprite, p.my_texture, sfTrue);
    p = init_positions(p);
    return (p);
}

display_t init_positions(display_t p)
{
    p.inv.x = 0;
    p.inv.y = 0;
    p.score = 0;
    p.score = 0;
    p.time2 = 0;
    p.time;
    p.rec.left = 0;
    p.rec.top = 0;
    p.rec.width = 50;
    p.rec.height = 50;
    p.p_my_sprite.x = 130;
    p.p_my_sprite.y = 940;
    p.p_disp1.y = 980;
    p.p_disp2.y = 930;
    p.p_disp3.y = 930;
    p.p_disp4.y = 930;
    p.dep = 0;
    p.jump = 0;
    p.scale1.x = 6;
    p.scale1.y = 4.6;
    p.p_body.x = 300;
    p.p_body.y = 880;
    p.p_body2.x = 300;
    p.p_body2.y = 880;
    p.p_body3.x = 300;
    p.p_body3.y = 880;
    p.p_body4.x = 300;
    p.p_body4.y = 880;
    p.body_scale.x = 0.4;
    p.body_scale.y = 0.4;
    sfSprite_setScale(p.my_body, p.body_scale);
    sfSprite_setScale(p.my_body2, p.body_scale);
    sfSprite_setScale(p.my_body3, p.body_scale);
    sfSprite_setScale(p.my_body4, p.body_scale);
    sfSprite_setScale(p.p1, p.scale1);
    sfSprite_setScale(p.p4, p.scale1);
    sfSprite_setScale(p.p2, p.scale1);
    sfSprite_setScale(p.p3, p.scale1);
    p.scaleb.x = 6;
    p.scaleb.y = 4.9;
    p.scale_nuage.x = 0.3;
    p.scale_nuage.y = 0.4;
    p.p_nuage.x = 130;
    p.p_nuage.y = 180;
    p.p_nuage2.x = 600;
    p.p_nuage2.y = 60;
    p.p_nuage3.x = 1100;
    p.p_nuage3.y = 190;
    p.p_nuage4.x = 1600;
    p.p_nuage4.y = 90;
    sfSprite_setScale(p.nuage, p.scale_nuage);
    sfSprite_setScale(p.nuage2, p.scale_nuage);
    sfSprite_setScale(p.nuage3, p.scale_nuage);
    sfSprite_setScale(p.nuage4, p.scale_nuage);
    sfSprite_setScale(p.b1, p.scaleb);
    sfSprite_setScale(p.bb1, p.scaleb);
    return (p);
}

void one_sprite(display_t p, sfClock *chrono)
{
    p.time = sfClock_getElapsedTime(chrono);
    p.time2 = p.time.microseconds / 100000;
    if (p.time2 > 2) {
        sfClock_restart(chrono);
        p.time2 = 0;
    }
    p.rec.left = 50 * p.time2;
    sfSprite_setTextureRect(p.my_sprite, p.rec);
}

void display_sprite(display_t p, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, p.b1, NULL);
    sfRenderWindow_drawSprite(window, p.bb1, NULL);
    sfRenderWindow_drawSprite(window, p.p1, NULL);
    sfRenderWindow_drawSprite(window, p.p2, NULL);
    sfRenderWindow_drawSprite(window, p.p3, NULL);
    sfRenderWindow_drawSprite(window, p.p4, NULL);
    sfRenderWindow_drawSprite(window, p.my_body, NULL);
    sfRenderWindow_drawSprite(window, p.my_body2, NULL);
    sfRenderWindow_drawSprite(window, p.my_body3, NULL);
    sfRenderWindow_drawSprite(window, p.my_body4, NULL);
    sfRenderWindow_drawSprite(window, p.nuage, NULL);
    sfRenderWindow_drawSprite(window, p.nuage2, NULL);
    sfRenderWindow_drawSprite(window, p.nuage3, NULL);
    sfRenderWindow_drawSprite(window, p.nuage4, NULL);
    sfRenderWindow_drawSprite(window, p.my_sprite, NULL);
}
