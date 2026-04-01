/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:00:28 by tpirinen          #+#    #+#             */
/*   Updated: 2026/04/01 15:40:08 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int draw_loop(t_game *game)
{
	t_player	*player = &game->player;

	move_player(player);
	clear_image(game);


	
	// draws a 3D raycast
	float fraction = PI / 3 / WIDTH;
	float start_x = player->angle - PI / 6;
	int i = 0;
	while (i < WIDTH)
	{
		draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}

	
	// draws player onto minimap
	draw_player(player->x, player->y, 20, 0x00FF00, game);
	draw_map(game);

	
	// Draws a set amount of rays into players FOV on minimap
	int		ray_count = 30;
	float	step;
	float	ray_angle;
	int		j = 0;

	if (ray_count < 2)
		ray_count = 2;
	step = player->fov / (ray_count - 1);
	ray_angle = player->angle - (player->fov / 2.0f);
	i = 0;
	while (j < ray_count)
	{
		draw_line_map(player, game, ray_angle);
		ray_angle += step;
		j++;
	}


	mlx_put_image_to_window(game->mlx, game->window, game->image, 0, 0);
	return (0);
}
