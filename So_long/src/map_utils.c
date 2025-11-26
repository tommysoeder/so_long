#include "so_long.h"

void	sanitize_map_lines(t_map *map)
{
	int	y;
	int	len;

	y = 0;
	while (y < map->height)
	{
		len = ft_strlen(map->grid[y]);
		if (len > 0 && map->grid[y][len - 1] == '\r')
			map->grid[y][len - 1] = '\0';
		y++;
	}
	if (map->height > 0)
		map->width = ft_strlen(map->grid[0]);
}
