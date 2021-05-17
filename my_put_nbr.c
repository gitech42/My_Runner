/*
** EPITECH PROJECT, 2020
** putnbr
** File description:
** 
*/

#include "my.h"

int  my_put_nbr(int nb)
{
    int i = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            i = (nb % 10);
            nb = (nb - i) / 10;
            my_put_nbr(nb);
            my_putchar('0' + i);
        }
        else
            my_putchar(nb % 10 + '0');
    }
    return 0;
}
