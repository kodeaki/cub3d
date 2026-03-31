/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:00:28 by tpirinen          #+#    #+#             */
/*   Updated: 2026/03/31 17:13:31 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int draw_loop(t_game *game)
{
	t_player	*player = &game->player;

	move_player(player);
	clear_image(game);
	draw_square(player->x - 10, player->y - 10, 20, 0x00FF00, game);
	
	// Below draws one line from player to a wall
	// float	ray_x = player->x;
	// float	ray_y = player->y;
	// float	cos_angle = cos(player->angle);
	// float	sin_angle = sin(player->angle);
	// while(!touch(ray_x, ray_y, game))
	// {
	// 	put_pixel(ray_x + 10, ray_y + 10, 0xFF0000, game);
	// 	ray_x += cos_angle;
	// 	ray_y += sin_angle;
	// }

	// Draws a set amount of rays into a 90degree FOV
	int		ray_count = 300;
	float	step;
	float	ray_angle;
	int		i;

	if (ray_count < 2)
		ray_count = 2;
	step = player->fov / (ray_count - 1);
	ray_angle = player->angle - (player->fov / 2.0f);
	i = 0;
	while (i < ray_count)
	{
		draw_line(player, game, ray_angle);
		ray_angle += step;
		i++;
	}

	draw_map(game);
	

	mlx_put_image_to_window(game->mlx, game->window, game->image, 0, 0);
	return (0);
}
