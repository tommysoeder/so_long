/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:05:04 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:05:05 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood(char **grid, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'F')
		return ;
	grid[y][x] = 'F';
	flood(grid, x + 1, y, map);
	flood(grid, x - 1, y, map);
	flood(grid, x, y + 1, map);
	flood(grid, x, y - 1, map);
}

static void	count_reachable(t_game *game, char **copy, int *c_seen, int *e_seen)
{
	int	x;
	int	y;

	*c_seen = 0;
	*e_seen = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'C' && copy[y][x] == 'F')
				(*c_seen)++;
			if (game->map.grid[y][x] == 'E' && copy[y][x] == 'F')
				*e_seen = 1;
			x++;
		}
		y++;
	}
}

void	check_path(t_game *game)
{
	char	**copy;
	int		collect_seen;
	int		exit_seen;

	copy = dup_grid(&game->map);
	if (!copy)
		error_exit(game, "Error de memoria al duplicar mapa");
	flood(copy, game->map.player_x, game->map.player_y, &game->map);
	count_reachable(game, copy, &collect_seen, &exit_seen);
	free_grid(copy, game->map.height);
	if (collect_seen != game->map.collect_count || !exit_seen)
		error_exit(game, "No hay un camino válido para todos los C y E");
}
