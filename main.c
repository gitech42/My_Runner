
/*
** EPITECH PROJECT, 2021
** runner
** File description:
** 
*/

#include "my.h"

void my_runner(display_t p)
{
    sfVector2f posi = {320, 5};
    sfClock *chrono;
    chrono = sfClock_create();
    p = init_sprite(p);
    sfVector2f pos = {50, 50,};
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "my_runner", sfClose | sfResize, NULL);
    sfEvent event;
    sfRenderWindow_setFramerateLimit(window, 60);
    sfSprite_setOrigin(p.my_sprite, pos);
    
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        one_sprite(p, chrono);
        while (sfRenderWindow_pollEvent(window, &event))
            if(event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        p.jump += 1;
        p = action(p);
        p = action2(p);
        p = space(p);
        display_sprite(p, window);
        if (touch(p, window) == 84) {
            sfRenderWindow_close(window);
            my_putstr("You loose\n");
            my_putstr("SCORE: ");
            my_put_nbr(p.score);
            my_putchar('\n');
        }
        if (p.score > 160) {
        my_putstr("You win\n");
        my_putstr("Score: ");
        my_put_nbr(160);
        my_putchar('\n');
        sfRenderWindow_close(window);
        }
        p = score(p, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
display_t action(display_t p)
{
    sfSprite_setPosition(p.nuage, p.p_nuage);
    sfSprite_setPosition(p.nuage2, p.p_nuage2);
    sfSprite_setPosition(p.nuage3, p.p_nuage3);
    sfSprite_setPosition(p.nuage4, p.p_nuage4);
    sfSprite_setPosition(p.my_sprite, p.p_my_sprite);
    sfSprite_setPosition(p.my_body, p.p_body);
    sfSprite_setPosition(p.my_body2, p.p_body2);
    sfSprite_setPosition(p.my_body3, p.p_body3);
    sfSprite_setPosition(p.my_body4, p.p_body4);
    sfSprite_setPosition(p.p1, p.p_disp1);
    sfSprite_setPosition(p.p2, p.p_disp2);
    sfSprite_setPosition(p.p3, p.p_disp3);
    sfSprite_setPosition(p.p4, p.p_disp4);
    sfSprite_setPosition(p.b1, p.p_back);
    sfSprite_setPosition(p.bb1, p.p_bback);
    return (p);
}

display_t action2(display_t p)
{
    p.p_back.x = (p.dep * 0.5) + 5 + 1920;
    p.p_bback.x = (p.dep * 0.5) + 5;
    p.p_body.x = (p.dep * 2) + 5 - 1920;
    p.p_body2.x = (p.dep * 2) + 5 + 1800;
    p.p_body3.x = (p.dep * 2) + 5 + 1920;
    p.p_body4.x = (p.dep * 2) + 5 + 3840;
    p.p_disp1.x = (p.dep * 2) + 5 - 1920;
    p.p_disp2.x = (p.dep * 2) + 5;
    p.p_disp3.x	= (p.dep * 2) + 5 + 1920;
    p.p_disp4.x	= (p.dep * 2) + 5 + 3840;
    p.p_nuage.x = (p.dep * 2) + 5 - 1800;
    p.p_nuage2.x = (p.dep * 1.3) + 5 + 2000;
    p.p_nuage3.x = (p.dep * 1.3) + 5 + 3100;
    p.p_nuage4.x = (p.dep * 1.3) + 5 + 3600;

    p.dep -= 6;
    if (p.dep < -1920) {
        p.p_disp2.x = (p.dep * 2) + 5 + 5760;
        p.p_disp3.x = (p.dep * 2) + 5 + 7680;
        p.p_nuage2.x = (p.dep * 1.3) + 5 + 4700;
        p.p_nuage.x = (p.dep * 1.3) + 5 + 7400;
    }
    if (p.dep < -1400) {
        p.p_body2.x = (p.dep * 2) + 5 + 4700;
        p.p_body3.x = (p.dep * 2) + 5 + 6800;
        p.p_body.x = (p.dep * 2) + 5 + 7400;
    }
    if (p.dep < -3840)
        p.dep = 0;
    return (p);
}

display_t score(display_t p, sfRenderWindow *window)
{
    sfVector2f posi = {320, 5};

    if (sfSprite_getPosition(p.my_sprite).x <= 130)
        p.score += 0.2;
    sfText_setString(p.text, my_itoa(p.score));
    sfText_setFont(p.text, p.font);
    sfText_setCharacterSize(p.text, 250);
    sfText_setPosition(p.text, posi);
    sfRenderWindow_drawText(window, p.text, NULL);
    return (p);
}

int touch(display_t p, sfRenderWindow *window)
{
    sfVector2f posi = {320, 5};
    char *str ="game over";
    if (sfSprite_getPosition(p.my_body).x <= 130) {
        if (sfSprite_getPosition(p.my_body).x >= 100 && sfSprite_getPosition(p.my_body).x <= 200) {
            if (sfSprite_getPosition(p.my_sprite).y >= 920 && sfSprite_getPosition(p.my_sprite).y >= 940) {
                return (84);
            }
        }
    }
    if (sfSprite_getPosition(p.my_body2).x <= 130) {
        if (sfSprite_getPosition(p.my_body2).x >= 100 && sfSprite_getPosition(p.my_body2).x <= 200) {
            if (sfSprite_getPosition(p.my_sprite).y >= 920 && sfSprite_getPosition(p.my_sprite).y >= 940)
                return (84);
        }
    }
    if (sfSprite_getPosition(p.my_body3).x <= 130) {
        if (sfSprite_getPosition(p.my_body3).x >= 100 && sfSprite_getPosition(p.my_body3).x <= 200) {
            if (sfSprite_getPosition(p.my_sprite).y >= 920 && sfSprite_getPosition(p.my_sprite).y >= 940) {
                return (84);
            }
        }
    }
    if (sfSprite_getPosition(p.my_body4).x <= 130) {
        if (sfSprite_getPosition(p.my_body4).x >= 100 && sfSprite_getPosition(p.my_body4).x <= 200) {
            if (sfSprite_getPosition(p.my_sprite).y >= 920 && sfSprite_getPosition(p.my_sprite).y >= 940) {
                return (84);
            }
        }
    }
    return (0);
}
