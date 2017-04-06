#include "filler.h"
#include <ncurses.h>

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
}

static void	end_print(char *line)
{
	printw("%s", line);
	free(line);
	if (get_next_line(0, &line) == 0)
		return ;
	else
		end_print(line);
}

static void	init_colors()
{
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_RED, COLOR_RED);
	init_pair(4, COLOR_GREEN, COLOR_GREEN);
	init_pair(5, COLOR_WHITE, COLOR_WHITE);
}

int			main(void)
{
	char		*line;
	t_player	*player;
	int			k;

	player = init_player();
	initscr();
	start_color();
	init_colors();
	keypad(stdscr, TRUE);
	attron(COLOR_PAIR(1));
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
				end_print(line);
				break;
			}
	}
	free(line);
	free_player(player);
	k = getch();
	if (k == KEY_UP)
		endwin();
	return (0);
}
