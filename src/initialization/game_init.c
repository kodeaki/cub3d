/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:05:00 by tpirinen          #+#    #+#             */
/*   Updated: 2026/03/31 15:09:32 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_game *game)
{
	player_init(&game->player);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->image, &game->bits_per_pixel,
			&game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx, game->window, game->image, 0, 0);
}
