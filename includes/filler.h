/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:25:47 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/29 18:21:06 by gvandeve         ###   ########.fr       */
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
	char	esymb[3];
	int		ipiece[2];
	int		iplateau[2];
	char	**piece;
	char	**plateau;
	int		rsp[2];
	int		nb_prt;
}				t_player;

typedef struct	s_pos
{
	int				pos[2];
	struct s_pos	*next;
}				t_pos;

int			main(void);
t_player	*init_player(void);
void		free_player(t_player *player);
void		scrap_start(t_player *player, char *line);
void		scrap_tab(int *tab_info, char ***tab, char *line);
void		print_tab(char **tab, int length);
void		push_next_line(char *line);
t_pos		*create_item(void);
t_pos		*add_elem(int x, int y, t_pos *lst);
t_pos		*fill_pos_player(t_player *ply, int x, int y, t_pos *lst);
t_pos		*fill_pos_eplayer(t_player *ply, int x, int y, t_pos *lst);
t_pos		*fill_pos_pic(t_player *ply, int x, int y, t_pos *lst);
void		calc_player_response(t_player *player);
void		show_list(t_pos *lst);
void		free_lst(t_pos *lst);
t_pos		*remove_first_elem(t_pos *lst);
void		remove_next_elem(t_pos *lst);
void		filter_ply(t_player *player);

#endif
















