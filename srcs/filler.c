/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:11:44 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/29 18:20:17 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	print_rsp(int x, int y)
{
	char	*nbx;
	char	*nby;

	nbx = ft_itoa(x);
	nby = ft_itoa(y);
	ft_putstr(nbx);
	ft_putstr(" ");
	ft_putstr(nby);
	ft_putstr("\n");
	free(nbx);
	free(nby);
}

static void	reload_plateau(t_player *player, char *line)
{
	free_tab(player->plateau, player->iplateau[0]);
	free(player->plateau);
	scrap_tab(player->iplateau, &player->plateau, line);
}

static void	reload_piece(t_player *player, char *line)
{
	free_tab(player->piece, player->ipiece[0]);
	free(player->piece);
	scrap_tab(player->ipiece, &player->piece, line);
	calc_player_response(player);
	print_rsp(player->rsp[0], player->rsp[1]);
}

int			main(void)
{
	char		*line;
	t_player	*player;

	player = init_player();
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "$$$", 3) == 0)
				scrap_start(player, line);
		if (ft_strncmp(line, "Plateau", 7) == 0)
			reload_plateau(player, line);
		if (ft_strncmp(line, "Piece", 5) == 0)
			reload_piece(player, line);
		if (ft_strncmp(line, "==", 2) == 0)
			{
				free(line);
				break ;
			}
		free(line);
	}
	free_player(player);
	return (0);
}
