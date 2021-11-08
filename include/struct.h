/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-alexis.amadei
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct matchstick_s
{
    char **tab;
    int size;
    int av1;
    int av2;
    int column;
    int maxstick;
    int maxline;
    int match;
    int line;
    bool game;
}matchstick_t;

#endif /* !STRUCT_H_ */