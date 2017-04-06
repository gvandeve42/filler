/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:28:18 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/06 16:16:31 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_bord(t_player *ply, int i, int j)
{
	int		count;
	char	**tab;

	count = 0;
	tab = ply->plateau;
	count += is_verti_h(i, j, tab, ply);
	count += is_verti_b(i, j, tab, ply);
	count += is_hori_g(i, j, tab, ply);
	count += is_hori_d(i, j, tab, ply);
	if (count > 0)
		return (1);
	else
		return (0);
}

void		filter_ply(t_player *player)
{
	int		i;
	int		j;
	char	**tab;
	int		*info;

	i = 0;
	j = 0;
	tab = player->plateau;
	info = player->iplateau;
	while (i < info[0])
	{
		while (j < info[1])
		{
			if ((tab[i][j] == player->symb[0] ||
				tab[i][j] == player->symb[1]) &&
				is_bord(player, i, j))
				tab[i][j] = 'a';
			j++;
		}
		j = 0;
		i++;
	}
}
