/*
** EPITECH PROJECT, 2021
** 
** File description:
** 
*/

#include "my.h"

char *my_itoa(int nb)
{
    int size = 0;
    char *str;

    for (int a = nb; a > 9; size++)
        a = a / 10;
    str = malloc(sizeof(char) * size + 1);
    str[size + 1] = '\0';
    for (int i = size; i >= 0; i--) {
        str[i] = 48 + (nb % 10);
        nb = nb / 10;
    }
    return (str);
}
