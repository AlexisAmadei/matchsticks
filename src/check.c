/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-alexis.amadei
** File description:
** check
*/

#include "matchsticks.h"

void update_map(matchstick_t *game)
{
    int j = game->column;
    int i = game->line;

    for (int c = 0; c != game->match; ++c) {
        for (; j != 0; --j) {
            if (game->tab[i][j] == '|') {
                game->tab[i][j] = ' ';
                break;
            }
        }
    }
}

int count_match_line(matchstick_t *game, int line)
{
    int match = 0;

    for (int j = 0; j != game->size; ++j)
        if (game->tab[line][j] == '|')
            ++match;
    return match;
}

bool check_line(matchstick_t *game)
{
    if (game->line > game->av1) {
        my_putstr("Error: this line is out of range\n");
        return false;
    } else
        return true;
}

int check_match(matchstick_t *game)
{
    int match = 0;

    if (game->match > game->av2) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(game->av2);
        my_putstr(" matches per turn\n");
        return 0;
    }
    for (int j = 0; j != game->size; ++j)
        if (game->tab[game->line][j] == '|')
            ++match;
    if (game->match > match) {
        my_putstr("Error: not enough matches on this line\n");
        player(game);
    }
    return 0;
}
