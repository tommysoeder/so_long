#include "so_long.h"

void	error_exit(t_game *game, const char *msg)
{
	if (msg)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd((char *)msg, 2);
		ft_putstr_fd("\n", 2);
	}
	free_game(game);
	exit(msg ? 1 : 0);
}

