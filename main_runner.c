/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    display_t p;
    if (ac < 2) {
        my_putstr("./my_runner: bad arguments: 0 given but 1 is required\n");
        my_putstr("retry with -h\n");
        my_putstr("84\n");
        return (84);
    }
    if (my_strcmp(av[1], "-h") == 0)
        hoption();
    if (my_strcmp(av[1], "-i") == 0)
        run_infinite(p);
    if (my_strcmp(av[1], "map.png") == 0)
        my_runner(p);
}
