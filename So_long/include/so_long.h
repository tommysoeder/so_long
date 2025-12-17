/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:03:04 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:03:06 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> 
# include "mlx.h"
# include "libft.h" 

# define KEY_ESC    65307
# define KEY_W      119
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100

# define TILE_SIZE  96

# define WALL_TX    "textures/wall.xpm"
# define FLOOR_TX   "textures/floor.xpm"
# define PLAYER_TX  "textures/player.xpm"
# define COLLECT_TX "textures/collect.xpm"
# define EXIT_TX    "textures/exit.xpm"

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		player_count;
	int		exit_count;
	int		collect_count;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	int		moves;
	int		collected;
}			t_game;

void	init_game(t_game *game);
void	start_game(t_game *game);

void	read_map(const char *filename, t_game *game);
void	validate_map(t_game *game);
int		is_rectangular(t_map *map);
int		is_surrounded_by_walls(t_map *map);

void	check_path(t_game *game);

void	load_textures(t_game *game);
void	render_map(t_game *game);

int		key_press(int keycode, t_game *game);
int		close_window(t_game *game);

void	error_exit(t_game *game, const char *msg);
void	free_map(t_map *map);
void	free_game(t_game *game);
void    sanitize_map_lines(t_map *map);
char	**dup_grid(t_map *map);
void	free_grid(char **grid, int height);
void	fill_image_solid(t_game *game, void *img, int color);
void	load_texture_or_die(t_game *game, void **dst, const char *path);


#endif
