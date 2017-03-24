#include "filler.h"

int		main(void)
{
	char		*line;
	t_player	*player;

	player = init_player();
	while (get_next_line(0, &line))
		{
			ft_putstr_fd("[read_vm] :", 2);
			ft_putstr_fd(line, 2);
			ft_putstr_fd("\n", 2);
			if (ft_strncmp(line, "$$$", 3))
				scrap_start(player, line);
			ft_printf("STRUCT: nb=[%d] symb=[%s]\n", player->nb, player->symb);
		}
	free(player);
	return (0);
}
