#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 15:09:43 by gvandeve          #+#    #+#              #
#    Updated: 2017/04/13 16:06:17 by gvandeve         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	gvandeve.filler
DIRSRC		=	./srcs
DIROBJ		=	./objs
INCLUDE		=	./includes
SRC			=	$(DIRSRC)/calc.c \
$(DIRSRC)/filler.c \
$(DIRSRC)/filter_pos.c \
$(DIRSRC)/is_avaible_2.c \
$(DIRSRC)/list.c \
$(DIRSRC)/scrap.c \
$(DIRSRC)/strat_att.c \
$(DIRSRC)/strat_get.c \
$(DIRSRC)/strat_list.c \
$(DIRSRC)/def_strat.c \
$(DIRSRC)/filter.c \
$(DIRSRC)/init.c \
$(DIRSRC)/is_next.c \
$(DIRSRC)/pos_rec.c \
$(DIRSRC)/srch_f_pic.c \
$(DIRSRC)/strat_fill.c \
$(DIRSRC)/strat_init.c \
$(DIRSRC)/utils.c \

OBJ			=	calc.o \
filler.o \
filter_pos.o \
is_avaible_2.o \
list.o \
scrap.o \
strat_att.o \
strat_get.o \
strat_list.o \
def_strat.o \
filter.o \
init.o \
is_next.o \
pos_rec.o \
srch_f_pic.o \
strat_fill.o \
strat_init.o \
utils.o \

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
