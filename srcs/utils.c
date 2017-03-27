#include "filler.h"

void	print_tab(char **tab, int length)
{
	int		i;

	i = 0;
	while (i < length)
		ft_printf("|||||%s|||||\n", tab[i++]);
}

void	free_player(t_player *player)
{
	int		i;

	i = 0;
	while (i < player->ipiece[0])
		free(player->piece[i++]);
	i = 0;
	while (i < player->iplateau[0])
		free(player->plateau[i++]);
	free(player);
}

void	push_next_line(char *line)
{
	get_next_line(0, &line);
	free(line);
}
