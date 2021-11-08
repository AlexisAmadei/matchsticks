##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/getnbr.c 		\
		src/utils.c 		\
		src/print.c			\
		src/fill_stars.c 	\
		src/player.c 		\
		src/check.c			\
		src/ai.c 			\
		src/check_end.c		\
		src/loop.c

OBJ	=	$(SRC:.c=.o)

NAME = matchstick

I = include/

all:

	gcc -c $(SRC) -g -Wall -Wextra -I include/ -g3
	gcc -o $(NAME) $(SRC) -g -Wall -Wextra -I include/ -g3
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	clear

re:     fclean all
