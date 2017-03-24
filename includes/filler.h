/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:25:47 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/23 15:26:11 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

typedef struct	s_player
{
	int		nb;
	char	symb[3];
	int		vpiece[2];
	char	**piece;
}				t_player;

int			main(void);
void		scrap_start(t_player *player, char *line);
t_player	*init_player();

#endif
