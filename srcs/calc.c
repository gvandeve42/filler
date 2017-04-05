/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:12:04 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/30 19:25:31 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	srch_for_piece(t_player *ply, int *coor, t_pos *piece, int *add)
{
	int	t_1;
	int	t_2;

	while (piece != NULL)
		{
			t_1 = coor[0] + piece->pos[0] - add[0];
			t_2 = coor[1] + piece->pos[1] - add[1];
			if (t_1 < ply->iplateau[0] && t_1 >= 0 &&
				t_2 < ply->iplateau[1] && t_2 >= 0)
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
	return (1);
}

int		is_avaible(t_player *ply, int *coor, t_pos *piece, int *add)
{
	ply->nb_prt = 0;
	if (srch_for_piece(ply, coor, piece, add))
		{
			if (ply->nb_prt == 1)
				return (1);
			else
				return (0);
		}
	return (0);
}

static int		analyse_plc(t_player *ply, t_pos *piece)
{
	int	*coor;

	coor = (int*)ft_memalloc(2 * sizeof(int));
	coor[0] = 0;
	coor[1] = 0;
	while (ply->g_strat(ply, &coor))
		{
			if (ply->p_strat(ply, coor, piece))
				{
					free(coor);
					return (1);
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
	t_pos			*piece;
	static int		start;

	piece = NULL;
	if (start == 0)
		start = def_strat(player, player->symb[0], player->esymb[0]);
	else
		def_strat(player, player->symb[1], player->esymb[1]);
	filter_ply(player);
	piece = model_piece(player, piece);
	if (!analyse_plc(player, piece))
		{
			player->rsp[0] = 0;
			player->rsp[1] = 0;
		}
	free_lst(piece);
}










