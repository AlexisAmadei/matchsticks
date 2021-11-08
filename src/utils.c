/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-alexis.amadei
** File description:
** my_putstr
*/

#include "matchsticks.h"

void my_putchar(char c)
{
    write (1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int my_strlen(char *str)
{
    int len = 0;

    for (; str[len] != '\0'; ++len);
    return len;
}

int my_put_nbr(int nb)
{
    long print = nb;
    if (print == 0) {
        my_putchar('0');
        return (0);
    }
    if (print < 0) {
        my_putchar('-');
        print *= -1;
    }
    while (print > 0) {
        long tmp = print;
        int i = 1;
        int j = 0;
        for (; tmp >= 10; i *= 10, j++) tmp /= 10;
        my_putchar(tmp + '0');
        if (print == tmp * i && print >= 10)
            for (; j > 0; j--) my_putchar('0');
        print -= tmp * i;
    }
    return (0);
}