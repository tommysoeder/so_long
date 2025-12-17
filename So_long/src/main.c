/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:05:40 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:05:42 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUso: ./so_long mapa.ber\n", 2);
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	read_map(argv[1], &game);
	validate_map(&game);
	check_path(&game);
	init_game(&game);
	start_game(&game);
	free_game(&game);
	return (0);
}
