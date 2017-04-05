#include "filler.h"

static void	calc_strat(t_player *ply, int *coor_j, int *coor_e)
{
	if (coor_j[0] <= coor_e[0] && coor_j[1] <= coor_e[1])
		{
			ply->g_strat = &get_next_coor_dr;
			ply->p_strat = &test_all_dr;
		}
	if (coor_j[0] <= coor_e[0] && coor_j[1] >= coor_e[1])
		{
			ply->g_strat = &get_next_coor_dl;
			ply->p_strat = &test_all_dl;
		}
	if (coor_j[0] >= coor_e[0] && coor_j[1] >= coor_e[1])
		{
			ply->g_strat = &get_next_coor_ul;
			ply->p_strat = &test_all_ul;
		}
	if (coor_j[0] >= coor_e[0] && coor_j[1] <= coor_e[1])
		{
			ply->g_strat = &get_next_coor_ur;
			ply->p_strat = &test_all_ur;
		}
}

static void grep_coor(int i, int j, int *coor)
{
	coor[0] = i;
	coor[1] = j;
}

int		def_strat(t_player *ply, char pc, char ec)
{
	int		i;
	int		j;
	int		coor_j[2];
	int		coor_e[2];

	i = 0;
	j = 0;
	while (i < ply->iplateau[0])
		{
			while (j < ply->iplateau[1])
				{
					if (ply->plateau[i][j] == pc)
						grep_coor(i, j, coor_j);
					if (ply->plateau[i][j] == ec)
						grep_coor(i, j, coor_e);
					j++;
				}
			j = 0;
			i++;
		}
	calc_strat(ply, coor_j, coor_e);
	return (1);
}
