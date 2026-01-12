/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:06:05 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:06:07 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map(t_game *game)
{
	map_check_shape(game);
	map_check_walls(game);
	map_check_content(game);
	check_path(game);
}
