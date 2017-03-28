#include "filler.h"

t_player	*init_player()
{
	t_player	*player;

	player = (t_player*)ft_memalloc(sizeof(t_player));
	return (player);
}

t_pos		*create_item()
{
	t_pos	*item;

	item = (t_pos*)ft_memalloc(sizeof(t_pos));
	item->next = NULL;
	return (item);
}
