/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-alexis.amadei
** File description:
** check_end
*/

#include "matchsticks.h"

int check_end(matchstick_t *game)
{
    int i = 0;
    int j = 0;
    int nb_match = 0;

    for (; i <= game->maxline; i++) {
        for (j = 0; j < game->column - 1; j++) {
            if (game->tab[i][j] == '|')
                nb_match++;
        }
    }
    return nb_match;
}

int check_win(matchstick_t *game)
{
    char *win = "I lost... snif... but I'll get you next time!!\n";

    if (check_end(game) == 0) {
        my_putstr(win);
        return 1;
    } else
        return 0;
}

int check_loose(matchstick_t *game)
{
    char *loose = "You lost, too bad...\n";

    if (check_end(game) == 0) {
        my_putstr(loose);
        return 2;
    } else
        return 0;
}