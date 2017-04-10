#include "filler.h"

int	att_strat(t_player *ply, int *coor, t_pos *piece)
{
	coor[0] = 0;
	coor[1] = 0;
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
	return (0);
}

int	end_strat(t_player *ply, int *coor, t_pos *piece)
{
	coor[0] = 0;
	coor[1] = 0;
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
