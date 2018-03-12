##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a_makefile_for_the_lib
##

CC=		gcc
NAME=		libmy.a
FLAGS=		-Wall -Wextra

SRC_DIR=        $(realpath .)

SRC=		$(SRC_DIR)/my_putchar.c \
		$(SRC_DIR)/my_putstr.c \
		$(SRC_DIR)/my_strlen.c \
		$(SRC_DIR)/my_memset.c \
		$(SRC_DIR)/my_strcpy.c \
		$(SRC_DIR)/my_strcmp.c \
		$(SRC_DIR)/my_getnbr.c \
		$(SRC_DIR)/my_strcat.c \
		$(SRC_DIR)/my_putnbr.c \
		$(SRC_DIR)/my_isalpha.c \
		$(SRC_DIR)/my_show_tab.c \

OBJ=            $(SRC:.c=.o)

all :           $(NAME)

$(NAME):
		$(CC) -c $(SRC) $(FLAGS)
		ar rc $(NAME) $(OBJ)
		cp my.h ../../include
		cp $(NAME) ../

.PHONY: clean

clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:		fclean all
