/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** getnbr.c
*/

#include "matchsticks.h"

int get_neg(char const *str, int i)
{
    int res = 1;
    i--;
    for (; i > 0 && (str[i] == '-' || str[i] == '+'); i--)
        if (str[i] == '-')
            res *= -1;
    return res;
}

int my_getnbr(char const *str)
{
    long long res = 0;
    int i = 0;
    int neg = 1;

    for (; str[i] && (str[i] < '0' || str[i] > '9'); i++);
    if (str[i] && i != 0)
        neg = get_neg(str, i);
    for (; str[i] && str[i] >= '0' && str[i] <= '9'; i++) {
        res *= 10;
        res += str[i] - '0';
    }
    res *= neg;
    if (res > 2147483647)
        res = 0;
    if (res < -2147483648)
        res = 0;
    return (res);
}