/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-alexis.amadei
** File description:
** print
*/

#include "matchsticks.h"

int print_tab(char **tab, int line, int col)
{
    for (int i = 0; i != line; i++) {
        for (int j = 0; j != col; j++)
            my_putchar(tab[i][j]);
        my_putchar('\n');
    }
    return 0;
}

void print_game_board(matchstick_t *game)
{
    game->tab = (char **)malloc(sizeof(char *) * (game->av1 + 2));
    int column = (game->av1 * 2) + 1;

    game->maxstick = (2 * game->av2);
    game->tab = fill_stars(game->tab, game->av1, column);
    for (int i = 1; i - 1 != game->av1; ++i) {
        for (int j = 1; j != column - 1; ++j)
            game->tab[i][j] = (game->av1 - i >= j ||
                game->av1 + i <= j) ? ' ' : '|';
    }
    game->size = column;
    print_tab(game->tab, game->av1 + 2, column);
    game->column = column;
}

void resum_p(matchstick_t *game)
{
    my_putstr("Player removed ");
    my_put_nbr(game->match);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->line);
    my_putchar('\n');
}
