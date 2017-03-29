/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:12:04 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/29 18:13:06 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	return (NULL);
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
	return (NULL);
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
	return (NULL);
}

void			calc_player_response(t_player *player)
{
	print_tab(player->plateau, player->iplateau[0]);
	filter_ply(player);
	print_tab(player->plateau, player->iplateau[0]);
}










