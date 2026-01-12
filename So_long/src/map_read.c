/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:05:55 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:05:56 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static void	build_grid(t_game *game, char *content)
{
	game->map.grid = ft_split(content, '\n');
	free(content);
	if (!game->map.grid || !game->map.grid[0])
		error_exit(game, "No se pudo leer el mapa o está vacío");
	game->map.height = count_lines(game->map.grid);
	game->map.width = ft_strlen(game->map.grid[0]);
	sanitize_map_lines(&game->map);
}

void	read_map(const char *filename, t_game *game)
{
	char	*content;

	content = read_file_to_str(filename);
	if (!content || content[0] == '\0')
	{
		free(content);
		error_exit(game, "No se pudo leer el mapa o está vacío");
	}
	build_grid(game, content);
}
