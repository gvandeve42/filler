#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 15:09:43 by gvandeve          #+#    #+#              #
#    Updated: 2017/03/23 15:22:42 by gvandeve         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	gvandeve.filler
DIRSRC		=	./srcs
DIROBJ		=	./objs
INCLUDE		=	./includes
SRC			=	$(DIRSRC)/*.c
OBJ			=	*.o
LIB			=	libftprintf/libftprintf.a
CFLAGS		=	-Wall -Wextra -Werror
CC			=	gcc

all: $(NAME)

$(NAME):
	make -C libftprintf re
	$(CC) -c $(FLAGS) $(SRC) -I $(INCLUDE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
	make -C libftprintf fclean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	../resources/filler_vm -f ../resources/maps/map00 -p1 gvandeve.filler -p2 gvandeve.filler
