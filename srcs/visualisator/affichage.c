/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:26:46 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/06 16:27:13 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <ncurses.h>

static void	print_colored_line(char *line)
{
	while (*line != '\0')
	{
		if (*line == '.')
			attron(COLOR_PAIR(5));
		if (*line == 'O' || *line == 'o')
			attron(COLOR_PAIR(2));
		if (*line == 'X' || *line == 'x')
			attron(COLOR_PAIR(3));
		if (*line == '*')
			attron(COLOR_PAIR(4));
		printw("%c%c", *line, *line);
		line++;
	}
	attron(COLOR_PAIR(1));
}

static void	print_tab_w(char **tab, int length)
{
	int		i;

	i = 0;
	while (i < length)
	{
		printw("[%3d] ", i, tab[i]);
		print_colored_line(tab[i]);
		printw("\n");
		i++;
	}
}

static void	print_intro(t_player *player)
{
	printw("\n           FILLER-VISUALISATOR          \n\n");
	printw(" Player 1 : %s %s\n", player->esymb, player->name_1);
	printw(" Player 2 : %s %s\n\n", player->symb, player->name_2);
}

static void	print_htab(int len)
{
	int i;

	i = 0;
	printw("%6s", "");
	while (i < len)
		(i > 9) ? printw("%d ", (i++ % 9)) : printw("%d ", i++);
	printw("\n");
}

void		print_visu(t_player *player)
{
	clear();
	print_intro(player);
	printw("\n PLATEAU : \n\n");
	print_htab(player->iplateau[1]);
	print_tab_w(player->plateau, player->iplateau[0]);
	printw("\n PIECE : \n\n");
	print_htab(player->ipiece[1]);
	print_tab_w(player->piece, player->ipiece[0]);
	refresh();
}
