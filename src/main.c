/*
** EPITECH PROJECT, 2020
** mathsticks
** File description:
** main.c
*/

#include "matchsticks.h"

matchstick_t *init_struct(void)
{
    matchstick_t *game = malloc(sizeof(matchstick_t));

    game->tab = NULL;
    game->av1 = 0;
    game->av2 = 0;
    game->size = 0;
    game->column = 0;
    game->maxstick = 0;
    game->maxline = 0;
    game->match = 0;
    game->line = 0;
    game->game = true;
    return game;
}

static void error_syntax(void)
{
    my_putstr("Syntax error\n");
    my_putstr("Usage: ./matchstick size nb-sticks.\n");
}

int main(int ac, char **argv)
{
    if (ac == 3) {
        if (argv[1][0] == '-' || argv[2][0] == '-')
            return 84;
        else
            return (loop(argv[1], argv[2]));
    } else {
        error_syntax();
        return 84;
    }
    return 0;
}