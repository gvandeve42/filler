/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_avaible_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:53:29 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/13 15:53:34 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				is_avaible_2(t_player *ply, int *coor, t_pos *piece, int *add)
{
	ply->nb_prt = 0;
	if (srch_for_piece_2(ply, coor, piece, add))
	{
		if (ply->nb_prt == 1)
			return (1);
	}
	return (0);
}
