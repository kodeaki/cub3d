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

static void	draw_ray_minimap(t_player *player, t_game *game,
		t_vector ray_dir)
{
	double	len;
	double	ray_x;
	double	ray_y;

	len = sqrt(ray_dir.x * ray_dir.x + ray_dir.y * ray_dir.y);
	if (len > 0.0)
	{
		ray_dir.x /= len;
		ray_dir.y /= len;
	}
	ray_x = player->pos.x;
	ray_y = player->pos.y;
	while (!touch(game, ray_x, ray_y))
	{
		put_pixel(game, 0xFF0000,
			(int)(ray_x * game->minimap.cell),
			(int)(ray_y * game->minimap.cell));
		ray_x += ray_dir.x * 0.1;
		ray_y += ray_dir.y * 0.1;
	}
}

// Draws a set amount of rays into players FOV on minimap
void	draw_rays(t_player *player, t_game *game)
{
	int			ray_count;
	double		step;
	double		camera_x;
	int			i;
	t_vector	ray_dir;

	ray_count = 50;
	if (ray_count < 2)
		ray_count = 2;
	step = 2.0 / (ray_count - 1);
	camera_x = -1.0;
	i = 0;
	while (i < ray_count)
	{
		ray_dir.x = player->dir.x + player->plane.x * camera_x;
		ray_dir.y = player->dir.y + player->plane.y * camera_x;
		draw_ray_minimap(player, game, ray_dir);
		camera_x += step;
		i++;
	}
}
