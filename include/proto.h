/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-alexis.amadei
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

#include "struct.h"

//getnbr.c
int my_getnbr(char const *str);
int get_neg(char const *str, int i);

//main.c
int main(int ac, char **argv);
matchstick_t *init_struct(void);

//loop.c
int loop(char *nb, char *nb2);

//utils.c
void my_putstr(char *str);
void my_putchar(char c);
int my_strlen(char *str);
int my_put_nbr(int nb);

//print.c
int print_tab(char **tab, int line, int col);
void print_game_board(matchstick_t *game);
void resum_p(matchstick_t *game);

//fill_stars.c
char **fill_stars(char **tab, int line, int column);
void destroy(matchstick_t *game);

//player.c
int player(matchstick_t *game);
int ai(matchstick_t *game);

//check.c
void update_map(matchstick_t *game);
int count_match_line(matchstick_t *game, int line);
bool check_line(matchstick_t *game);
int check_match(matchstick_t *game);

//check_end.c
int check_end(matchstick_t *game);
int check_win(matchstick_t *game);
int check_loose(matchstick_t *game);

#endif /* !PROTO_H_ */
