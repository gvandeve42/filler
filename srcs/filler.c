#include "filler.h"

int		main(void)
{
	char		*line;
	t_player	*player;

	player = init_player();
	while (get_next_line(0, &line) == 1)
		{
			ft_printf("[read  p%d %s] :%s\n", player->nb, player->symb, line);
			if (ft_strncmp(line, "$$$", 3) == 0)
				scrap_start(player, line);
			if (ft_strncmp(line, "Plateau", 7) == 0)
				scrap_tab(player->iplateau, &player->plateau, line);
			if (ft_strncmp(line, "Piece", 5) == 0)
				{
					scrap_tab(player->ipiece, &player->piece, line);
					//calc_player_response(player);
					ft_putstr("0 0\n");
				}
			free(line);
		}
	free_player(player);
	return (0);
}
