/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:15:05 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/30 19:05:29 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_tab(char **tab, int length)
{
	int		i;

	i = 0;
	while (i < length)
	{
		ft_printf("[%3d] %s\n", i, tab[i]);
		i++;
	}
}

void	free_tab(char **tab, int len)
{
	int		i;

	i = 0;
	while (i < len)
		free(tab[i++]);
}

void	free_player_v(t_player *player)
{
	free(player->name_1);
	free(player->name_2);
	free(player);
}

void	free_player(t_player *player)
{
	free_tab(player->plateau, player->iplateau[0]);
	free_tab(player->piece, player->ipiece[0]);
	free(player->name_1);
	free(player->name_2);
	free(player->piece);
	free(player->plateau);
	free(player);
}
