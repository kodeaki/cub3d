/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:51:44 by tpirinen          #+#    #+#             */
/*   Updated: 2026/05/02 16:05:23 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ray(t_player *player, t_game *game, float start_x)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = player->x;
	ray_y = player->y;
	while (!touch(ray_x, ray_y, game))
	{
		put_pixel(ray_x / 4, ray_y / 4, 0xFF0000, game);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}

// Draws a set amount of rays into players FOV on minimap
void	draw_rays(t_player *player, t_game *game)
{
	int		ray_count;
	float	step;
	float	ray_angle;
	int		i;

	ray_count = 30;
	if (ray_count < 2)
		ray_count = 2;
	step = player->fov / (ray_count - 1);
	ray_angle = player->angle - (player->fov / 2.0f);
	i = 0;
	while (i < ray_count)
	{
		draw_ray(player, game, ray_angle);
		ray_angle += step;
		i++;
	}
}
