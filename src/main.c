/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:05:59 by tpirinen          #+#    #+#             */
/*   Updated: 2026/03/31 15:54:08 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	
	(void)argc;
	(void)argv;
	// if (argc != 2)
	// {
	// 	printf("Error:\nUse ./cub3d /path/to/map.cub\n");
	// 	return (-1);
	// }

	// Parsing
	create_map(&game);
	
	// Initiate stuff
	game_init(&game);


	// mlx_hooks
	mlx_hook(game.window, 2, 1L<<0, key_press, &game.player);
	mlx_hook(game.window, 3, 1L<<1, key_release, &game.player);

	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	
	return (0);
}
