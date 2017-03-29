/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:12:37 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/29 13:20:20 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player*)ft_memalloc(sizeof(t_player));
	return (player);
}

t_pos		*create_item(void)
{
	t_pos	*item;

	item = (t_pos*)ft_memalloc(sizeof(t_pos));
	item->next = NULL;
	return (item);
}
