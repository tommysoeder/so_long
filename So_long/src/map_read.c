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

static char	*join_and_free(char *s1, char *s2)
{
	char	*joined;

	if (!s1)
		return (s2);
	joined = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (joined);
}

static char	*read_file_to_str(const char *filename)
{
	int		fd;
	ssize_t	br;
	char	buf[1024 + 1];
	char	*chunk;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = NULL;
	br = read(fd, buf, 1024);
	while (br > 0)
	{
		buf[br] = '\0';
		chunk = ft_strdup(buf);
		if (!chunk)
		{
			free(content);
			close(fd);
			return (NULL);
		}
		content = join_and_free(content, chunk);
		if (!content)
		{
			close(fd);
			return (NULL);
		}
		br = read(fd, buf, 1024);
	}
	close(fd);
	if (br < 0)
	{
		free(content);
		return (NULL);
	}
	return (content);
}

static int	count_lines(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	read_map(const char *filename, t_game *game)
{
	char	*content;

	if (!ft_strnstr(filename, ".ber", ft_strlen(filename)))
		error_exit(game, "El archivo no tiene extensión .ber");
	content = read_file_to_str(filename);
	if (!content)
		error_exit(game, "No se pudo abrir el archivo del mapa");
	if (content[0] == '\0')
	{
		free(content);
		error_exit(game, "El mapa está vacío");
	}
	game->map.grid = ft_split(content, '\n');
	free(content);
	if (!game->map.grid || !game->map.grid[0])
		error_exit(game, "Mapa inválido");
	game->map.height = count_lines(game->map.grid);
	game->map.width = ft_strlen(game->map.grid[0]);
	sanitize_map_lines(&game->map);
}
