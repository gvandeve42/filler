/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:56:42 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/13 15:56:44 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	att_strat(t_player *ply, int *coor, t_pos *piece)
{
	coor[0] = -1;
	coor[1] = -1;
	while (ply->g_strat(ply, &coor))
	{
		if (test_all_a(ply, coor, piece))
		{
			free(coor);
			return (1);
		}
	}
	return (0);
}

int	nrm_strat(t_player *ply, int *coor, t_pos *piece)
{
	coor[0] = -1;
	coor[1] = -1;
	while (ply->g_strat(ply, &coor))
	{
		if (ply->p_strat(ply, coor, piece))
		{
			free(coor);
			return (1);
		}
	}
	return (0);
}

int	end_strat(t_player *ply, int *coor, t_pos *piece)
{
	coor[0] = -1;
	coor[1] = -1;
	while (ply->g_strat(ply, &coor))
	{
		if (test_all_end(ply, coor, piece))
		{
			free(coor);
			return (1);
		}
	}
	return (0);
}
