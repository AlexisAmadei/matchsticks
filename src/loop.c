/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-alexis.amadei
** File description:
** loop
*/

#include "matchsticks.h"

static void init_val(matchstick_t *game, char *av1, char *av2)
{
    game->av1 = my_getnbr(av1);
    game->av2 = my_getnbr(av2);
}

static int error(matchstick_t *game)
{
    if (game->av2 < 1 || game->av1 < 1 || game->av1 >= 100)
        return 84;
    return 0;
}

int while_bcl(matchstick_t *game)
{
    int res = 0;

    my_putstr("\nYour turn:\n");
    res = player(game);
    if (res == 84)
        return 84;
    else if (res != 0) {
        print_tab(game->tab, game->av1 + 2, (game->av1 * 2) + 1);
        return 2;
    }
    print_tab(game->tab, game->av1 + 2, (game->av1 * 2) + 1);
    res = ai(game);
    print_tab(game->tab, game->av1 + 2, (game->av1 * 2) + 1);
    if (res != 0)
        return 1;
    return 0;
}

int loop(char *av1, char *av2)
{
    matchstick_t *game = init_struct();
    int res = 0;

    init_val(game, av1, av2);
    if (error(game) == 84)
        return 84;
    game->maxline = game->av1;
    print_game_board(game);
    while (res == 0) {
        res = while_bcl(game);
    }
    if (res == 84)
        res = 0;
    destroy(game);
    return res;
}