##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a_makefile_for_projetcs
##

CC	=	gcc -g3

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include

NAME	=	tetris

SRCS	=	srcs/brain.c				\
		srcs/tetriminos_error_handling.c	\
		srcs/help_flag.c			\
		srcs/draw_debug.c			\
		srcs/get_next_line.c			\
		srcs/modif_debug.c			\
		srcs/the_switch.c			\

OBJS	=	$(SRCS:.c=.o)

LIB =		-L./lib -lmy

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C ./lib/my
		$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
		$(RM) $(OBJS)
		make -C ./lib/my clean

fclean: 	clean
		$(RM) $(NAME)
		$(RM) lib/*.a
		make -C ./lib/my fclean

re: 		fclean all

.PHONY: all clean fclean re
