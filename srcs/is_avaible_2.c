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
