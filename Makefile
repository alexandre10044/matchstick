##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC	=	src/main.c \
		src/my_bot.c \
		src/my_engine.c \
		src/my_error.c \
		src/my_get.c \
		src/my_map.c \
		src/my_put.c \
		src/my_reader.c \
		src/my_utils.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Werror -Wextra \
		-I include -O3

LDFLAGS	+=	-lm

NAME	=	matchstick

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
