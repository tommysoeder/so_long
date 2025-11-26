#include "so_long.h"

int	is_rectangular(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->grid[i]);
		if (len != map->width)
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (y == 0 || y == map->height - 1
				|| x == 0 || x == map->width - 1)
			{
				if (map->grid[y][x] != '1')
				{
					// DEBUG opcional: puedes comentar estas líneas en versión final
					ft_printf("Borde roto en (%d,%d): '%c' (esperaba '1')\n",
						x, y, map->grid[y][x]);
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}

static void	count_and_check_chars(t_game *game)
{
	int		x;
	int		y;
	t_map	*map;

	map = &game->map;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!ft_strchr("01CEP", map->grid[y][x]))
				error_exit(game, "Caracter desconocido en el mapa");
			if (map->grid[y][x] == 'P')
			{
				map->player_count++;
				map->player_x = x;
				map->player_y = y;
			}
			else if (map->grid[y][x] == 'E')
				map->exit_count++;
			else if (map->grid[y][x] == 'C')
				map->collect_count++;
			x++;
		}
		y++;
	}
}

void	validate_map(t_game *game)
{
	if (!is_rectangular(&game->map))
		error_exit(game, "El mapa no es rectangular");
	if (!is_surrounded_by_walls(&game->map))
		error_exit(game, "El mapa no está rodeado por paredes");
	count_and_check_chars(game);
	if (game->map.player_count != 1)
		error_exit(game, "Debe haber exactamente 1 posición inicial (P)");
	if (game->map.exit_count != 1)
		error_exit(game, "Debe haber exactamente 1 salida (E)");
	if (game->map.collect_count < 1)
		error_exit(game, "Debe haber al menos un coleccionable (C)");
}
