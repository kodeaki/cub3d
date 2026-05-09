/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:05:59 by tpirinen          #+#    #+#             */
/*   Updated: 2026/05/06 18:11:54 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_game *game)
{
	clear_image(game);
	move_player(&game->player, game);
	// raycast(game, &game->player);
	raycast_texture(game);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	if (parsing(argc, argv, &game))
		ft_exit(1, "Usage: ./cub3d /path_to_file.cub");
	create_map(&game);
	game_init(&game);
	mlx_hook(game.window, 2, 1L << 0, key_press, &game);
	mlx_hook(game.window, 3, 1L << 1, key_release, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	ft_free(&game);
	return (0);
}
