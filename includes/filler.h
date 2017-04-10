/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:25:47 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/06 16:36:50 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_player	t_player;
typedef struct s_pos	t_pos;

struct		s_player
{
	int		nb;
	char	symb[3];
	char	*name_1;
	char	esymb[3];
	char	*name_2;
	int		ipiece[2];
	int		iplateau[2];
	char	**piece;
	char	**plateau;
	int		rsp[2];
	int		nb_prt;
	int		(*g_strat)(t_player *ply, int **coor);
	int		(*p_strat)(t_player *ply, int *coor, t_pos *piece);
};

struct		s_pos
{
	int		pos[2];
	t_pos	*next;
};

int			main(void);
void		free_tab(char **tab, int len);
t_player	*init_player(void);
void		free_player(t_player *player);
void		scrap_start(t_player *player, char *line);
void		scrap_tab(int *tab_info, char ***tab, char *line);
void		print_tab(char **tab, int length);
void		push_next_line(char *line);
t_pos		*create_item(void);
t_pos		*add_elem(int x, int y, t_pos *lst);
void		calc_player_response(t_player *player);
void		free_lst(t_pos *lst);
void		filter_ply(t_player *player);
int			is_avaible(t_player *ply, int *coor, t_pos *piece, int *add);
int			is_avaible_2(t_player *ply, int *coor, t_pos *piece, int *add);
int			is_verti_b(int i, int j, char **tab, t_player *ply);
int			is_verti_h(int i, int j, char **tab, t_player *ply);
int			is_hori_d(int i, int j, char **tab, t_player *ply);
int			is_hori_g(int i, int j, char **tab, t_player *ply);
int			test_all_a(t_player *ply, int *coor, t_pos *piece);
int			test_all_ul(t_player *ply, int *coor, t_pos *piece);
int			test_all_ur(t_player *ply, int *coor, t_pos *piece);
int			test_all_dl(t_player *ply, int *coor, t_pos *piece);
int			test_all_dr(t_player *ply, int *coor, t_pos *piece);
int			test_all_end(t_player *ply, int *coor, t_pos *piece);
void		init_var_ul(int *i, int *j, int **coor);
void		init_var_ur(int *i, int *j, int **coor, t_player *ply);
void		init_var_dl(int *i, int *j, int **coor, t_player *ply);
void		init_var_dr(int *i, int *j, int **coor, t_player *ply);
int			get_next_coor_ul(t_player *ply, int **coor);
int			get_next_coor_dl(t_player *ply, int **coor);
int			get_next_coor_dr(t_player *ply, int **coor);
int			get_next_coor_ur(t_player *ply, int **coor);
int			def_strat(t_player *ply, char pc, char ec);
int			filter_pos(t_player *ply);
void		filter_pos_rec(t_player *ply, int i, int j, int *test);
void		test_pos_up(t_player *ply, int i, int j, int *test);
void		test_pos_down(t_player *ply, int i, int j, int *test);
void		test_pos_right(t_player *ply, int i, int j, int *test);
void		test_pos_left(t_player *ply, int i, int j, int *test);
int			srch_for_piece(t_player *ply, int *coor, t_pos *piece, int *add);
int			srch_for_piece_2(t_player *ply, int *coor, t_pos *piece, int *add);

void		print_visu(t_player *player);
void		scrap_start_v(t_player *player, char *line);

#endif
