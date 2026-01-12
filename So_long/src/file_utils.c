/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:31:52 by tomamart          #+#    #+#             */
/*   Updated: 2026/01/12 12:31:55 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*append_chunk(char *content, char *chunk)
{
	char	*tmp;

	if (!content)
		return (chunk);
	tmp = ft_strjoin(content, chunk);
	free(content);
	free(chunk);
	return (tmp);
}

static char	*read_fd_to_str(int fd)
{
	char	*content;
	char	*chunk;
	int		bytes;
	char	buf[1024 + 1];

	content = NULL;
	bytes = read(fd, buf, 1024);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		chunk = ft_strdup(buf);
		if (!chunk)
			return (free(content), NULL);
		content = append_chunk(content, chunk);
		if (!content)
			return (NULL);
		bytes = read(fd, buf, 1024);
	}
	if (bytes < 0)
		return (free(content), NULL);
	return (content);
}

char	*read_file_to_str(const char *filename)
{
	int		fd;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = read_fd_to_str(fd);
	close(fd);
	return (content);
}
