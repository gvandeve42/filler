/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:13:26 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/29 13:23:05 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		scrap_start(t_player *player, char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i++] == 'p')
		{
			player->nb = ft_atoi(&line[i]);
			player->symb[0] = (player->nb == 1) ? 'O' : 'X';
			player->symb[1] = (player->nb == 1) ? 'o' : 'x';
			player->esymb[0] = (player->nb == 1) ? 'X' : 'O';
			player->esymb[1] = (player->nb == 1) ? 'x' : 'o';
			return ;
		}
	}
}

void		scrap_start_v(t_player *player, char *line)
{
	int		i;
	int		anchor;

	i = 0;
	anchor = 0;
	while (line[i] != '\0')
	{
		if (line[i++] == 'p')
		{
			anchor = i;
			player->nb = ft_atoi(&line[i]);
			player->symb[0] = (player->nb == 1) ? 'O' : 'X';
			player->symb[1] = (player->nb == 1) ? 'o' : 'x';
			player->esymb[0] = (player->nb == 1) ? 'X' : 'O';
			player->esymb[1] = (player->nb == 1) ? 'x' : 'o';
		}
		if (line[i] == '[' && line[anchor] == '1')
			player->name_1 = ft_strdup(&line[i]);
		if (line[i] == '[' && line[anchor] == '2')
			player->name_2 = ft_strdup(&line[i]);
	}
	return ;
}

static void	scrap_info_tab(int *tab, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = line;
	while (*tmp != '\0')
	{
		if (ft_isdigit(*tmp))
		{
			tab[i++] = ft_atoi(tmp);
			while (ft_isdigit(*tmp))
				tmp++;
		}
		tmp++;
	}
}

void		scrap_tab(int *tab_info, char ***tab, char *line)
{
	int		i[2];
	char	**tmp;
	char	*tmp_line;

	i[0] = 0;
	i[1] = 0;
	tmp_line = line;
	scrap_info_tab(tab_info, tmp_line);
	*tab = (char**)ft_memalloc(tab_info[0] * sizeof(char*));
	tmp = *tab;
	while (i[0] < tab_info[0] && (get_next_line(0, &tmp_line) == 1))
	{
		if (*tmp_line != 'P' && *tmp_line != ' ')
		{
			while (tmp_line[i[1]] != '.' &&
					tmp_line[i[1]] != 'O' &&
					tmp_line[i[1]] != 'X' &&
					tmp_line[i[1]] != '*' &&
					tmp_line[i[1]] != '\0')
				i[1]++;
			tmp[i[0]] = (char*)ft_memalloc((tab_info[1] + 1) * sizeof(char));
			ft_strncpy(tmp[i[0]++], &tmp_line[i[1]], tab_info[1]);
		}
		free(tmp_line);
	}
}
