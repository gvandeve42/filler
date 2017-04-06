/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:26:01 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/06 16:26:12 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_var_ul(int *i, int *j, int **coor)
{
	if ((*coor)[0] == 0 && (*coor)[1] == 0)
	{
		*i = 0;
		*j = 0;
	}
}

void	init_var_ur(int *i, int *j, int **coor, t_player *ply)
{
	if ((*coor)[0] == 0 && (*coor)[1] == 0)
	{
		*i = 0;
		*j = (ply->iplateau[1] - 1);
	}
}

void	init_var_dl(int *i, int *j, int **coor, t_player *ply)
{
	if ((*coor)[0] == 0 && (*coor)[1] == 0)
	{
		*i = (ply->iplateau[0] - 1);
		*j = 0;
	}
}

void	init_var_dr(int *i, int *j, int **coor, t_player *ply)
{
	if ((*coor)[0] == 0 && (*coor)[1] == 0)
	{
		*i = (ply->iplateau[0] - 1);
		*j = (ply->iplateau[1] - 1);
	}
}
