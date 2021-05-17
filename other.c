/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** 
*/

#include "my.h"

void hoption(void)
{
    my_putstr("Runner created with CSFML\n");
    my_putstr("\nUSAGE\n");
    my_putstr(" ./my_runner map.png\n\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("-i        launch the game in infinity mode.\n");
    my_putstr("-h        print the usage and quit\n\n");
    my_putstr ("USER INTERACTIONS\n");
    my_putstr("  SPACE_KEY        jump.\n\n");
}

display_t run_infinite(display_t p)
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
        p = score(p, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    
}
