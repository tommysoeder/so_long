#include "so_long.h"

static void	try_move_player(t_game *game, int dx, int dy)
{
	int		nx;
	int		ny;
	char	*msg;

	nx = game->map.player_x + dx;
	ny = game->map.player_y + dy;
	if (nx < 0 || ny < 0 || nx >= game->map.width || ny >= game->map.height)
		return ;
	if (game->map.grid[ny][nx] == '1')
		return ;
	if (game->map.grid[ny][nx] == 'C')
	{
		game->collected++;
		game->map.grid[ny][nx] = '0';
	}
	if (game->map.grid[ny][nx] == 'E')
	{
		if (game->collected == game->map.collect_count)
		{
			game->moves++;
			ft_printf("Movimientos: %d\n", game->moves);
			ft_printf("¡Has ganado!\n");
			error_exit(game, NULL);
		}
		else
			return ;
	}
	game->map.player_x = nx;
	game->map.player_y = ny;
	game->moves++;
	ft_printf("Movimientos: %d\n", game->moves);
	render_map(game);
	(void)msg;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		error_exit(game, NULL);
	else if (keycode == KEY_W)
		try_move_player(game, 0, -1);
	else if (keycode == KEY_S)
		try_move_player(game, 0, 1);
	else if (keycode == KEY_A)
		try_move_player(game, -1, 0);
	else if (keycode == KEY_D)
		try_move_player(game, 1, 0);
	return (0);
}

int	close_window(t_game *game)
{
	error_exit(game, NULL);
	return (0);
}

void	start_game(t_game *game)
{
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}
