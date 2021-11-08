/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-alexis.amadei
** File description:
** ai
*/

#include "matchsticks.h"

static void resum_ai(int r_match, int r_line)
{
    my_putstr("AI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(r_match);
    my_putstr(" match(es) from line ");
    my_put_nbr(r_line);
    my_putchar('\n');
}

int ai(matchstick_t *game)
{
    int r_line = 1 + (rand() % game->maxline);
    int r_match = 0;
    int nb_match = count_match_line(game, r_line);

    if (nb_match == 0) {
        return ai(game);
    }
    r_match =  1 + (rand() % nb_match);
    if (count_match_line(game, r_line) == 0)
        ai(game);
    if (r_line > game->av1 || r_match > game->av2) {
        ai(game);
        return 0;
    }
    resum_ai(r_match, r_line);
    game->line = r_line;
    game->match = r_match;
    update_map(game);
    return check_win(game);
}