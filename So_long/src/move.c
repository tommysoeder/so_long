/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:53:09 by tomamart          #+#    #+#             */
/*   Updated: 2026/01/12 12:53:11 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_inside(t_game *game, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (x >= game->map.width || y >= game->map.height)
		return (0);
	return (1);
}

static void	win_game(t_game *game)
{
	game->moves++;
	ft_printf("Movimientos: %d\n", game->moves);
	ft_printf("¡Has ganado!\n");
	free_game(game);
	exit(EXIT_SUCCESS);
}

static int	can_step(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map.grid[y][x];
	if (tile == '1')
		return (0);
	if (tile == 'C')
	{
		game->collected++;
		game->map.grid[y][x] = '0';
	}
	if (tile == 'E')
	{
		if (game->collected == game->map.collect_count)
			win_game(game);
		return (0);
	}
	return (1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = game->map.player_x + dx;
	ny = game->map.player_y + dy;
	if (!is_inside(game, nx, ny))
		return ;
	if (!can_step(game, nx, ny))
		return ;
	game->map.player_x = nx;
	game->map.player_y = ny;
	game->moves++;
	ft_printf("Movimientos: %d\n", game->moves);
	render_map(game);
}
