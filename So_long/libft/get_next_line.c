/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 00:00:00 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/24 19:15:28 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_store(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = store_rest(stash);
	if (!line || line[0] == '\0')
	{
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
