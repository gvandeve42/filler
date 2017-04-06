#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 15:09:43 by gvandeve          #+#    #+#              #
#    Updated: 2017/04/06 16:55:09 by gvandeve         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	gvandeve.filler
DIRSRC		=	./srcs
DIROBJ		=	./objs
INCLUDE		=	./includes
SRC			=	$(DIRSRC)/*.c
OBJ			=	*.o
LIB			=	libft/libftprintf.a
CFLAGS		=	-Wall -Wextra -Werror
CC			=	gcc

all: $(NAME)

$(NAME):
	@make -C libft re
	@$(CC) -c $(FLAGS) $(SRC) -I $(INCLUDE)
	@$(CC) -g $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
	@make -C libft fclean

clean:
	@find . \( -name "#*#" -o -name "*~" \) -print -delete
	@rm -rf $(OBJ)
	@rm -f filler.trace

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: re
	@cp gvandeve.filler ../resources/players
	@../resources/filler_vm -f ../resources/maps/map02 -p1 ../resources/players/gvandeve.filler -p2 ../resources/players/gvandeve.filler | ./srcs/visualisator/a.out
