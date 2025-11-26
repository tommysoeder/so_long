#include "so_long.h"

static void	create_floor_fallback(t_game *game)
{
	int		x;
	int		y;
	int		bpp;
	int		line_len;
	int		endian;
	char	*data;
	int		color;

	game->img_floor = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!game->img_floor)
		error_exit(game, "No se pudo crear imagen de suelo");
	data = mlx_get_data_addr(game->img_floor, &bpp, &line_len, &endian);
	if (!data)
		error_exit(game, "No se pudo obtener data_addr de suelo");
	color = 0x00CCCCCC; // gris claro
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			*(int *)(data + y * line_len + x * (bpp / 8)) = color;
			x++;
		}
		y++;
	}
}

void	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, WALL_TX, &w, &h);
	if (!game->img_wall)
		error_exit(game, "Fallo cargando wall.xpm");

	game->img_floor = mlx_xpm_file_to_image(game->mlx, FLOOR_TX, &w, &h);
	if (!game->img_floor)
	{
		//ft_printf("Aviso: fallo cargando floor.xpm, usando suelo simple.\n");
		create_floor_fallback(game);
	}

	game->img_player = mlx_xpm_file_to_image(game->mlx, PLAYER_TX, &w, &h);
	if (!game->img_player)
		error_exit(game, "Fallo cargando player.xpm");

	game->img_collect = mlx_xpm_file_to_image(game->mlx, COLLECT_TX, &w, &h);
	if (!game->img_collect)
		error_exit(game, "Fallo cargando collect.xpm");

	game->img_exit = mlx_xpm_file_to_image(game->mlx, EXIT_TX, &w, &h);
	if (!game->img_exit)
		error_exit(game, "Fallo cargando exit.xpm");
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(game, "mlx_init falló");
	game->win = mlx_new_window(game->mlx,
			game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE,
			"so_long");
	if (!game->win)
		error_exit(game, "No se pudo crear la ventana");
	load_textures(game);
	game->moves = 0;
	game->collected = 0;
}
