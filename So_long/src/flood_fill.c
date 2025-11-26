#include "so_long.h"

static char	**dup_grid(t_map *map)
{
	char	**copy;
	int		i;

	copy = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

static void	free_grid_copy(char **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

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

void	check_path(t_game *game)
{
	char	**copy;
	int		x;
	int		y;
	int		collect_seen;
	int		exit_seen;

	copy = dup_grid(&game->map);
	if (!copy)
		error_exit(game, "Error de memoria al duplicar mapa");
	flood(copy, game->map.player_x, game->map.player_y, &game->map);
	collect_seen = 0;
	exit_seen = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'C' && copy[y][x] == 'F')
				collect_seen++;
			if (game->map.grid[y][x] == 'E' && copy[y][x] == 'F')
				exit_seen = 1;
			x++;
		}
		y++;
	}
	free_grid_copy(copy, game->map.height);
	if (collect_seen != game->map.collect_count || !exit_seen)
		error_exit(game, "No hay un camino válido para todos los C y E");
}
