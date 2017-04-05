#include "filler.h"

int		get_next_coor_ul(t_player *ply, int **coor)
{
	static int			i;
	static int			j;

	init_var_ul(&i, &j, coor);
	while (i < ply->iplateau[0])
		{
			while (j < ply->iplateau[1])
				{
					if (ply->plateau[i][j] == 'a')
						{
							if (i != (*coor)[0] || j != (*coor)[1])
								{
									(*coor)[0] = i;
									(*coor)[1] = j;
									return (1);
								}
						}
					j++;
				}
			j = 0;
			i++;
		}
	return (0);
}

int		get_next_coor_dl(t_player *ply, int **coor)
{
	static int			i;
	static int			j;

	init_var_dl(&i, &j, coor, ply);
	while (i >= 0)
		{
			while (j < ply->iplateau[1])
				{
					if (ply->plateau[i][j] == 'a')
						{
							if (i != (*coor)[0] || j != (*coor)[1])
								{
									(*coor)[0] = i;
									(*coor)[1] = j;
									return (1);
								}
						}
					j++;
				}
			j = 0;
			i--;
		}
	return (0);
}

int		get_next_coor_dr(t_player *ply, int **coor)
{
	static int			i;
	static int			j;

	init_var_dr(&i, &j, coor, ply);
	while (i >= 0)
		{
			while (j >= 0)
				{
					if (ply->plateau[i][j] == 'a')
						{
							if (i != (*coor)[0] || j != (*coor)[1])
								{
									(*coor)[0] = i;
									(*coor)[1] = j;
									return (1);
								}
						}
					j--;
				}
			j = (ply->iplateau[1] - 1);
			i--;
		}
	return (0);
}

int			get_next_coor_ur(t_player *ply, int **coor)
{
	static int			i;
	static int			j;

	init_var_ur(&i, &j, coor, ply);
	while (i < ply->iplateau[0])
		{
			while (j >= 0)
				{
					if (ply->plateau[i][j] == 'a')
						{
							if (i != (*coor)[0] || j != (*coor)[1])
								{
									(*coor)[0] = i;
									(*coor)[1] = j;
									return (1);
								}
						}
					j--;
				}
			j = (ply->iplateau[1] - 1);
			i++;
		}
	return (0);
}
