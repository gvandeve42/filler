#include "filler.h"

void	scrap_start(t_player *player, char *line)
{
	while (*line != '\0')
		{
			if(*line++ == 'p')
				{
					player->nb = ft_atoi(line);
					player->symb[0] = (player->nb == 1) ? 'O' : 'X' ;
					player->symb[1] = (player->nb == 1) ? 'o' : 'x' ;
					return ;
				}
		}
}
