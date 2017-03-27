#include "filler.h"

int		main(void)
{
	char		*line;
	t_player	*player;

	player = init_player();
	while (get_next_line(0, &line) == 1)
		{
			ft_printf("||%s||\n", line);
			if (ft_strncmp(line, "$$$", 3) == 0)
					scrap_start(player, line);
			if (ft_strncmp(line, "Plateau", 7) == 0)
				{
					scrap_tab(player->iplateau, &player->plateau, line);
					print_tab(player->plateau, player->iplateau[0]);
				}
			if (ft_strncmp(line, "Piece", 5) == 0)
				{
					scrap_tab(player->ipiece, &player->piece, line);
					print_tab(player->piece, player->ipiece[0]);
				}
			free(line);
		}
	free_player(player);
	return (0);
}
