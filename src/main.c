/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:05:59 by tpirinen          #+#    #+#             */
/*   Updated: 2026/04/21 14:20:10 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_game	game;
	
	// Parsing
	// if (parsing(argc, argv, &game))
	// 	ft_exit(1, "Usage: ./cub3d /path_to_file.cub");

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
