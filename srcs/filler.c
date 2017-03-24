#include "filler.h"

int		main(void)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (get_next_line(1, &line))
		ft_printf("L_NB[%5d] txt : %s", i++, line);
	return (0);
}
