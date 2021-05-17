/*
** EPITECH PROJECT, 2021
** 
** File description:
** 
*/

#include "my.h"

display_t space(display_t p)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && p.p_my_sprite.y == 940)
        p.jump = -20;
    p.p_my_sprite.y = p.p_my_sprite.y + p.jump;
    if (p.p_my_sprite.y > 940) {
        p.jump = 0;
        p.p_my_sprite.y = 940;
    }
    return (p);
}
