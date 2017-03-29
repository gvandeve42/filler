/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:12:54 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/29 17:13:15 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_lst(t_pos *lst)
{
	if (lst->next == NULL)
	{
		free(lst);
		return ;
	}
	else
	{
		free_lst(lst->next);
		free(lst);
	}
	return ;
}

t_pos	*remove_first_elem(t_pos *lst)
{
	t_pos	*tmp;

	tmp = lst->next;
	free(lst);
	lst = tmp;
	return (lst);
}

void	remove_next_elem(t_pos *lst)
{
	t_pos	*tmp;

	tmp = lst->next->next;
	free(lst->next);
	lst->next = tmp;
}

void	show_list(t_pos *lst)
{
	int	i;

	i = 0;
	while (lst->next != NULL)
	{
		ft_printf("\n||| maillon n%d x=%d y=%d |||\n", i++, lst->pos[0], lst->pos[1]);
		lst = lst->next;
	}
	ft_printf("\n||| maillon n%d x=%d y=%d |||\n", i++, lst->pos[0], lst->pos[1]);
	return ;
}

t_pos	*add_elem(int x, int y, t_pos *lst)
{
	t_pos	*tmp;

	tmp = lst;
	if (lst == NULL)
	{
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
