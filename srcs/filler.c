#include "filler.h"

int		main(void)
{
	char		*line;
	t_player	*player;

	player = init_player();
	while (get_next_line(0, &line))
		{
			if (ft_strncmp(line, "$$$", 3) == 0)
				scrap_start(player, line);
			if (ft_strncmp(line, "Plateau", 7) == 0)
				scrap_tab(player->iplateau, &player->plateau, line);
			if (ft_strncmp(line, "Piece", 5) == 0)
				{
					scrap_tab(player->ipiece, &player->piece, line);
					//calc_player_response(player);
					(player->nb == 1) ? ft_putstr("8 2\n") : ft_putstr("11 14\n");
				}
			if (ft_strncmp(line, "==", 2 == 0))
				{
					free(line);
					break ;
				}
				free(line);
		}
	free_player(player);
	return (0);
}
