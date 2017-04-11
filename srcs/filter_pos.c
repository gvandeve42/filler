#include "filler.h"

void	filter_pos_rec(t_player *ply, int i, int j, int *test)
{
	if (j - 1 >= 0)
		test_pos_left(ply, i, j, test);
	if (i - 1 >= 0)
		test_pos_up(ply, i, j, test);
	if (i + 1 < ply->iplateau[0])
		test_pos_down(ply, i, j, test);
	if (j + 1 < ply->iplateau[1])
		test_pos_right(ply, i, j, test);
	if (test[0] > 0 && test[1] > 0)
		ply->plateau[i][j] = 'l';
	if (test[0] > 0 && test[1] == 0)
		ply->plateau[i][j] = 'm';
	if (test[0] == 0 && test[1] > 0)
		ply->plateau[i][j] = 'y';
}

void	filter_pos(t_player *ply)
{
	int		i;
	int		j;
	int		test[2];

	i = 0;
	j = 0;
	while (i < ply->iplateau[0])
		{
			while (j < ply->iplateau[1])
				{
					if (ply->plateau[i][j] == '.')
						{
							test[0] = 0;
							test[1] = 0;
							filter_pos_rec(ply, i, j, test);
						}
					j++;
				}
			j = 0;
			i++;
		}
}
