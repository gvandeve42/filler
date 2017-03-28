#include "filler.h"
#include <stdio.h>

static t_pos	*calc_pos_ply(t_player *player)
{
	t_pos	*pos;
	int		i;
	int		j;

	pos = NULL;
	i = 0;
	j = 0;
	while (i < player->iplateau[0])
		{
			while (j < player->iplateau[1])
				{
					if (player->plateau[i][j] == player->symb[0])
						{
							pos = fill_pos_player(player, i, j, pos);
							return (pos);
						}
					j++;
				}
			j = 0;
			i++;
		}
}

static t_pos	*calc_pos_eply(t_player *player)
{
	t_pos	*pos;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < player->iplateau[0])
		{
			while (j < player->iplateau[1])
				{
					if (player->plateau[i][j] == player->esymb[0])
						{
							pos = fill_pos_eplayer(player, i, j, pos);
							return (pos);
						}
					j++;
				}
			j = 0;
			i++;
		}
}

static t_pos	*calc_pos_pic(t_player *player)
{
	t_pos	*pos;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < player->ipiece[0])
		{
			while (j < player->ipiece[1])
				{
					if (player->piece[i][j] == '*')
						{
							pos = fill_pos_pic(player, i, j, pos);
							return (pos);
						}
					j++;
				}
			j = 0;
			i++;
		}
}

void			calc_player_response(t_player *player)
{
	t_pos	*plylist;
	//t_pos	*eplylist;
	//t_pos	*piclist;

	plylist = calc_pos_ply(player);
	//eplylist = calc_pos_eply(player);
	//piclist = calc_pos_pic(player);
	ft_printf("\n\n |||Y %d %d Y||| \n\n", plylist->pos[0], plylist->pos[1]);
	player->rsp[0] = plylist->pos[0];
	player->rsp[1] = plylist->pos[1];
}
