/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:58:20 by tomamart          #+#    #+#             */
/*   Updated: 2026/01/12 12:09:15 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_img_data(t_game *game, void *img, int *line_len)
{
	char	*data;
	int		bpp;
	int		endian;

	data = mlx_get_data_addr(img, &bpp, line_len, &endian);
	if (!data)
		error_exit(game, "No se pudo obtener data_addr de imagen");
	if (bpp != 32)
		error_exit(game, "Formato de imagen no soportado");
	return (data);
}

void	fill_image_solid(t_game *game, void *img, int color)
{
	char	*data;
	int		line_len;
	int		x;
	int		y;

	data = get_img_data(game, img, &line_len);
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			*(int *)(data + y * line_len + x * 4) = color;
			x++;
		}
		y++;
	}
}

void	load_texture_or_die(t_game *game, void **dst, const char *path)
{
	int	w;
	int	h;

	*dst = mlx_xpm_file_to_image(game->mlx, (char *)path, &w, &h);
	if (!*dst)
		error_exit(game, "Error cargando textura");
}
