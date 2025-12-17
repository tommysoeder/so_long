/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:06:22 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:06:24 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == '1')
				put_img(game, game->img_wall, x, y);
			else
				put_img(game, game->img_floor, x, y);
			if (game->map.grid[y][x] == 'C')
				put_img(game, game->img_collect, x, y);
			else if (game->map.grid[y][x] == 'E')
				put_img(game, game->img_exit, x, y);
			x++;
		}
		y++;
	}
	put_img(game, game->img_player,
		game->map.player_x, game->map.player_y);
}
