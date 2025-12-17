/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:58:20 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/17 17:58:22 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_image_solid(t_game *game, void *img, int color)
{
	char	*data;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;

	data = mlx_get_data_addr(img, &bpp, &line_len, &endian);
	if (!data)
		error_exit(game, "No se pudo obtener data_addr de imagen");
	if (bpp != 32)
		error_exit(game, "Formato de imagen no soportado");
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
