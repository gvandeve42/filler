/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:11:18 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/06 16:11:50 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	is_verti_b(int i, int j, char **tab, t_player *ply)
{
	int	*info;

	info = ply->iplateau;
	if (i + 1 < info[0] && tab[i + 1][j] == '.')
		return (1);
	return (0);
}

int	is_verti_h(int i, int j, char **tab, t_player *ply)
{
	int	*info;

	info = ply->iplateau;
	if (i - 1 >= 0 && tab[i - 1][j] == '.')
		return (1);
	return (0);
}

int	is_hori_d(int i, int j, char **tab, t_player *ply)
{
	int	*info;

	info = ply->iplateau;
	if (j + 1 < info[1] && tab[i][j + 1] == '.')
		return (1);
	return (0);
}

int	is_hori_g(int i, int j, char **tab, t_player *ply)
{
	int	*info;

	info = ply->iplateau;
	if (j - 1 >= 0 && tab[i][j - 1] == '.')
		return (1);
	return (0);
}
