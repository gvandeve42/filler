/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisateur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:27:39 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/06 18:00:19 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <ncurses.h>
#include <curses.h>

static void	new_plateau(t_player *player, char *line)
{
	free_tab(player->plateau, player->iplateau[0]);
	free(player->plateau);
	scrap_tab(player->iplateau, &player->plateau, line);
}

static void	new_piece(t_player *player, char *line)
{
	free_tab(player->piece, player->ipiece[0]);
	free(player->piece);
	scrap_tab(player->ipiece, &player->piece, line);
	print_visu(player);
	usleep(15000);
}

static void	end_print(t_player *player, char *line)
{
	print_visu(player);
	printw("\n%s\n", line);
	free(line);
	while (get_next_line(0, &line))
	{
		printw("%s\n", line);
		free(line);
	}
	refresh();
}

static void	init_colors(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_RED, COLOR_RED);
	init_pair(4, COLOR_GREEN, COLOR_GREEN);
	init_pair(5, COLOR_WHITE, COLOR_WHITE);
	attron(COLOR_PAIR(1));
}

int			main(void)
{
	char		*line;
	t_player	*player;

	initscr();
	player = init_player();
	init_colors();
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "$$$", 3) == 0)
			scrap_start_v(player, line);
		if (ft_strncmp(line, "Plateau", 7) == 0)
			new_plateau(player, line);
		if (ft_strncmp(line, "Piece", 5) == 0)
			new_piece(player, line);
		if (ft_strncmp(line, "==", 2) == 0)
		{
			end_print(player, line);
			break ;
		}
		free(line);
	}
	free_player(player);
	sleep(3);
	endwin();
	return (0);
}
