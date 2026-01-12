/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:40:43 by tomamart          #+#    #+#             */
/*   Updated: 2026/01/12 12:40:45 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	reset_counts(t_game *game)
{
	game->map.player_count = 0;
	game->map.exit_count = 0;
	game->map.collect_count = 0;
}

static void	update_counts(t_game *game, char c, int x, int y)
{
	if (c == 'P')
	{
		game->map.player_count++;
		game->map.player_x = x;
		game->map.player_y = y;
	}
	else if (c == 'E')
		game->map.exit_count++;
	else if (c == 'C')
		game->map.collect_count++;
}

static void	check_required(t_game *game)
{
	if (game->map.player_count != 1)
		error_exit(game, "Debe haber exactamente 1 posición inicial (P)");
	if (game->map.exit_count != 1)
		error_exit(game, "Debe haber exactamente 1 salida (E)");
	if (game->map.collect_count < 1)
		error_exit(game, "Debe haber al menos un coleccionable (C)");
}

void	map_check_content(t_game *game)
{
	int		x;
	int		y;
	char	c;

	reset_counts(game);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			c = game->map.grid[y][x];
			if (!ft_strchr("01CEP", c))
				error_exit(game, "Caracter desconocido en el mapa");
			update_counts(game, c, x, y);
			x++;
		}
		y++;
	}
	check_required(game);
}
