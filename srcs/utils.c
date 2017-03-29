/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:15:05 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/29 13:15:08 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free(player->piece);
	free(player->plateau);
	free(player);
}
