/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:05:29 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:05:31 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_floor_fallback(t_game *game)
{
	game->img_floor = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!game->img_floor)
		error_exit(game, "No se pudo crear imagen de suelo");
	fill_image_solid(game, game->img_floor, 0x00CCCCCC);
}

static void	try_load_floor(t_game *game)
{
	int	w;
	int	h;

	game->img_floor = mlx_xpm_file_to_image(game->mlx, FLOOR_TX, &w, &h);
	if (!game->img_floor)
		create_floor_fallback(game);
}

void	load_textures(t_game *game)
{
	load_texture_or_die(game, &game->img_wall, WALL_TX);
	try_load_floor(game);
	load_texture_or_die(game, &game->img_player, PLAYER_TX);
	load_texture_or_die(game, &game->img_collect, COLLECT_TX);
	load_texture_or_die(game, &game->img_exit, EXIT_TX);
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
