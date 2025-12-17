/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:10:14 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/17 17:10:15 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
