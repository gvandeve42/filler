#include "filler.h"

t_pos	*add_elem(int x, int y, t_pos *lst)
{
	t_pos	*tmp;

	tmp = lst;

	ft_printf("Debut de (add_elem)");
	if (lst == NULL)
		{
			ft_printf("\n||TMP 1\n");
			tmp = create_item();
			tmp->pos[0] = x;
			tmp->pos[1] = y;
			return (tmp);
		}
	else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = create_item();
			tmp = tmp->next;
			tmp->pos[0] = x;
			tmp->pos[1] = y;
		}
	return (lst);
}
