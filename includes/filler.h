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
	int		ipiece[2];
	int		iplateau[2];
	char	**piece;
	char	**plateau;
	char	*rsp;
}				t_player;

int			main(void);
t_player	*init_player();
void		free_player(t_player *player);
void		scrap_start(t_player *player, char *line);
void		scrap_tab(int *tab_info, char ***tab, char *line);
void		print_tab(char **tab, int length);
void		push_next_line(char *line);

#endif
