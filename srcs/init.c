#include "filler.h"

t_player	*init_player()
{
	t_player	*player;

	player = (t_player*)ft_memalloc(sizeof(t_player));
	return (player);
}
