/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_checks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:31:41 by tomamart          #+#    #+#             */
/*   Updated: 2026/01/12 12:39:53 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_shape(t_game *game)
{
	int	y;
	int	len;

	y = 0;
	while (y < game->map.height)
	{
		len = (int)ft_strlen(game->map.grid[y]);
		if (len != game->map.width)
			error_exit(game, "El mapa no es rectangular");
		y++;
	}
}

void	map_check_walls(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (y == 0 || y == game->map.height - 1
				|| x == 0 || x == game->map.width - 1)
			{
				if (game->map.grid[y][x] != '1')
					error_exit(game, "El mapa no está rodeado por paredes");
			}
			x++;
		}
		y++;
	}
}
