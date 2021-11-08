/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-alexis.amadei
** File description:
** player
*/

#include "matchsticks.h"

int nb_matches(matchstick_t *game, int line)
{
    int j = 0;
    int nb_match = 0;

    for (; game->tab[line][j] != '\n'; ++j)
        if (game->tab[line][j] == '|')
            ++nb_match;
    return (nb_match);

}

int player(matchstick_t *game)
{
    char *buffer = NULL;
    size_t size;

    srand(time(NULL));
    do {
        my_putstr("Line: ");
        if (getline(&buffer, &size, stdin) <= 0)
            return 84;
        game->line = my_getnbr(buffer);
        if (check_line(game) == false)
            return player(game);
        my_putstr("Matches: ");
        if (getline(&buffer, &size, stdin) <= 0)
            return 84;
        game->match = my_getnbr(buffer);
        check_match(game);
    } while (game->line > game->maxline || game->match > game->maxstick
            || game->match > game->av2);
    resum_p(game);
    update_map(game);
    my_putchar('\n');
    free(buffer);
    return check_loose(game);
}