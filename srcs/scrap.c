#include "filler.h"

void	scrap_start(t_player *player, char *line)
{
	char	*tmp;

	tmp = line;
	while (*tmp != '\0')
		{
			if (*tmp++ == 'p')
				{
					player->nb = ft_atoi(line);
					player->symb[0] = (player->nb == 1) ? 'O' : 'X' ;
					player->symb[1] = (player->nb == 1) ? 'o' : 'x' ;
					return ;
				}
		}
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


void	scrap_tab(int *tab_info, char ***tab, char *line)
{
	int		i;
	int		j;
	char	**tmp;
	char	*tmp_line;

	i = 0;
	j = 0;
	tmp_line = line;
	scrap_info_tab(tab_info, tmp_line);
	*tab = (char**)ft_memalloc(tab_info[0] * sizeof(char*));
	tmp = *tab;
	get_next_line(0, &tmp_line);
	(*tmp_line == ' ') ? get_next_line(0, &tmp_line) : (void)tmp_line;
	while (i < tab_info[0])
		{
			get_next_line(0, &tmp_line);
			while (tmp_line[j] != '.' &&
				   tmp_line[j] != 'O' &&
				   tmp_line[j] != 'X' &&
				   tmp_line[j] != '*' &&
				   tmp_line[j] != '\0')
				j++;
			tmp[i] = (char*)ft_memalloc((tab_info[1] + 1) * sizeof(char));
			ft_strncpy(tmp[i++], &tmp_line[j], tab_info[1]);
		}
}
