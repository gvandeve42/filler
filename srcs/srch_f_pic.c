#include "filler.h"

int		srch_for_piece_2(t_player *ply, int *coor, t_pos *piece, int *add)
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
			if (ply->plateau[t_1][t_2] == 'l' ||
				ply->plateau[t_1][t_2] == 'm' ||
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
