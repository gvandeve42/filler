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

static int		is_avaible(t_player *ply, int *coor, t_pos *piece, int *add)
{
	int	t_1;
	int	t_2;
	t_pos	*tmp;

	tmp = piece;
	ply->nb_prt = 0;
	while (piece != NULL)
		{
			t_1 = coor[0] + piece->pos[0] - add[0];
			t_2 = coor[1] + piece->pos[1] - add[1];
			if (t_1 < ply->iplateau[0] &&
				t_1 > 0 &&
				t_2 < ply->iplateau[1] &&
				t_2 > 0)
				{
					if (ply->plateau[t_1][t_2] == '.' ||
						 ply->plateau[t_1][t_2] == 'a')
						{
							if (ply->plateau[t_1][t_2] == 'a')
								ply->nb_prt++;
						}
					else
						ply->nb_prt = -1000;
				}
			else
				return (0);
			piece = piece->next;
		}
	piece = tmp;
	if (ply->nb_prt == 1)
		return (1);
	else
		return (0);
}

static int		get_next_coor(t_player *ply, int **coor)
{
	t_bool		start;
	int			i;
	int			j;

	start = TRUE;
	i = (*coor)[0];
	j = (*coor)[1];
	while (i < ply->iplateau[0])
		{
			while (j < ply->iplateau[1])
				{
					if (ply->plateau[i][j] == 'a')
						{
							(*coor)[0] = i;
							(*coor)[1] = j;
							return (1);
						}
					j++;
				}
			j = 0;
			i++;
		}
	return (0);
}

static int		test_all(t_player *ply, int *coor, t_pos *piece)
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
							free (i);
							return (1);
						}
					i[1]++;
				}
			i[1] = 0;
			i[0]++;
		}
	free (i);
	return (0);
}

static int		analyse_plc(t_player *ply, t_pos *piece)
{
	int	*coor;

	coor = (int*)ft_memalloc(2 * sizeof(int));
	coor[0] = 0;
	coor[1] = 0;
	while (get_next_coor(ply, &coor))
		{
			if (test_all(ply, coor, piece))
				{
					free(coor);
					return (1);
				}
			if (coor[1] + 1 < ply->iplateau[1])
				coor[1]++;
			else
				{
					coor[0]++;
					coor[1] = 0;
				}
		}
	free(coor);
	return (0);
}

static t_pos	*model_piece(t_player *ply, t_pos *pic)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < ply->ipiece[0])
		{
			while (j < ply->ipiece[1])
				{
					if (ply->piece[i][j] == '*')
						pic = add_elem(i, j, pic);
					j++;
				}
			j = 0;
			i++;
		}
	return (pic);
}
void			calc_player_response(t_player *player)
{
	t_pos *piece;

	piece = NULL;
	filter_ply(player);
	piece = model_piece(player, piece);
	if (!analyse_plc(player, piece))
		{
			player->rsp[0] = 0;
			player->rsp[1] = 0;
		}
	free_lst(piece);
}










