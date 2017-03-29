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
			scrap_tab(player->iplateau, &player->plateau, line);
		if (ft_strncmp(line, "Piece", 5) == 0)
		{
			scrap_tab(player->ipiece, &player->piece, line);
			calc_player_response(player);
			print_rsp(player->rsp[0], player->rsp[1]);
		}
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
