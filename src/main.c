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

int	game_loop(t_game *game)
{
	t_player	*player;

	player = &game->player;
	clear_image(game);
	move_player(player, game);
	raycast(game, player);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;
	// if (parsing(argc, argv, &game))
	// 	ft_exit(1, "Usage: ./cub3d /path_to_file.cub");
	create_map(&game);
	game_init(&game);
	mlx_hook(game.window, 2, 1L << 0, key_press, &game.player);
	mlx_hook(game.window, 3, 1L << 1, key_release, &game.player);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
