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
OBJ			=	$(SRC:.c=.o)
OBJS		=	$(OBJ:%=$(DIROBJ)%)
CFLAGS		=	-Wall -Wextra -Werror
CC			=	gcc

all: $(NAME)

$(NAME):
	$(CC) -c $(FLAGS) $(SRC) -I $(INCLUDE) -o $(DIROBJ)
	$(COMP) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f %(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	../resources/filler_vm -f ../resources/maps/map00 -p1 gvandeve.filler -p2 gvandeve.filler