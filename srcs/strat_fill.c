/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:23:15 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/06 16:24:27 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		test_all_ul(t_player *ply, int *coor, t_pos *piece)
{
	int	*i;

	i = (int*)ft_memalloc(2 * sizeof(int));
	i[0] = 0;
	i[1] = 0;
	while (i[0] < ply->ipiece[0])
	{
		while (i[1] < ply->ipiece[1])
		{
			if (is_avaible(ply, coor, piece, i))
			{
				ply->rsp[0] = (coor[0] - i[0]);
				ply->rsp[1] = (coor[1] - i[1]);
				free(i);
				return (1);
			}
			i[1]++;
		}
		i[1] = 0;
		i[0]++;
	}
	free(i);
	return (0);
}

int		test_all_ur(t_player *ply, int *coor, t_pos *piece)
{
	int	*i;

	i = (int*)ft_memalloc(2 * sizeof(int));
	i[0] = 0;
	i[1] = ply->ipiece[1] - 1;
	while (i[0] < ply->ipiece[0])
	{
		while (i[1] >= 0)
		{
			if (is_avaible(ply, coor, piece, i))
			{
				ply->rsp[0] = (coor[0] - i[0]);
				ply->rsp[1] = (coor[1] - i[1]);
				free(i);
				return (1);
			}
			i[1]--;
		}
		i[1] = ply->ipiece[1] - 1;
		i[0]++;
	}
	free(i);
	return (0);
}

int		test_all_dl(t_player *ply, int *coor, t_pos *piece)
{
	int	*i;

	i = (int*)ft_memalloc(2 * sizeof(int));
	i[0] = ply->ipiece[0] - 1;
	i[1] = 0;
	while (i[0] >= 0)
	{
		while (i[1] < ply->ipiece[1])
		{
			if (is_avaible(ply, coor, piece, i))
			{
				ply->rsp[0] = (coor[0] - i[0]);
				ply->rsp[1] = (coor[1] - i[1]);
				free(i);
				return (1);
			}
			i[1]++;
		}
		i[1] = 0;
		i[0]--;
	}
	free(i);
	return (0);
}

int		test_all_dr(t_player *ply, int *coor, t_pos *piece)
{
	int	*i;

	i = (int*)ft_memalloc(2 * sizeof(int));
	i[0] = ply->ipiece[0] - 1;
	i[1] = ply->ipiece[1] - 1;
	while (i[0] >= 0)
	{
		while (i[1] >= 0)
		{
			if (is_avaible(ply, coor, piece, i))
			{
				ply->rsp[0] = (coor[0] - i[0]);
				ply->rsp[1] = (coor[1] - i[1]);
				free(i);
				return (1);
			}
			i[1]--;
		}
		i[1] = ply->ipiece[1] - 1;
		i[0]--;
	}
	free(i);
	return (0);
}
