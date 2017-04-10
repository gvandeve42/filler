#include "filler.h"

static int	e_is_next(t_player *ply, int i, int j)
{
	if (i + 1 < ply->iplateau[0])
		if (ply->plateau[i + 1][j] == ply->esymb[0] ||
			ply->plateau[i + 1][j] == ply->esymb[1])
			return (1);
	if (i - 1 >= 0)
		if (ply->plateau[i - 1][j] == ply->esymb[0] ||
			ply->plateau[i - 1][j] == ply->esymb[1])
			return (1);
	if (j + 1 < ply->iplateau[1])
		if (ply->plateau[i][j + 1] == ply->esymb[0] ||
			ply->plateau[i][j + 1] == ply->esymb[1])
			return (1);
	if (j - 1 >= 0)
		if (ply->plateau[i][j - 1] == ply->esymb[0] ||
			ply->plateau[i][j - 1] == ply->esymb[1])
			return (1);
	return (0);
}

static int	is_next_e(t_player *ply, int *coor, t_pos *piece, int *add)
{
	int	t_1;
	int	t_2;

	while (piece != NULL)
	{
		t_1 = coor[0] + piece->pos[0] - add[0];
		t_2 = coor[1] + piece->pos[1] - add[1];
		if (e_is_next(ply, t_1, t_2))
			return (1);
		piece = piece->next;
	}
	return (0);
}

int			test_all_a(t_player *ply, int *coor, t_pos *piece)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	while (i[0] < ply->ipiece[0])
	{
		while (i[1] < ply->ipiece[1])
		{
			if (is_avaible(ply, coor, piece, i))
			{
				if (is_next_e(ply, coor, piece, i))
					{
						ply->rsp[0] = (coor[0] - i[0]);
						ply->rsp[1] = (coor[1] - i[1]);
						return (1);
					}
			}
			i[1]++;
		}
		i[1] = 0;
		i[0]++;
	}
	return (0);
}
