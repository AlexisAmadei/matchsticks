/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-alexis.amadei
** File description:
** fill_stars
*/

#include "matchsticks.h"

char **fill_stars(char **tab, int line, int column)
{
    int i = 0;
    int j = 0;

    for (; i < line + 2; i++) {
        tab[i] = malloc(sizeof(char *) * (column + 3));
        for (j = 0; j < column + 2; ++j)
            tab[i][j] = '*';
        tab[i][j + 1] = '\0';
    }
    return tab;
}

void destroy(matchstick_t *game)
{
    int i = 0;

    for (; i < game->maxline; i++) {
        free(game->tab[i]);
    }
    free(game->tab);
    free(game);
}