/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:51:44 by tpirinen          #+#    #+#             */
/*   Updated: 2026/04/01 15:37:07 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_ray	init_ray(t_player *player, float angle)
{
	t_ray	ray;

	ray.origin.x = player->x;
	ray.origin.y = player->y;
	ray.hit = ray.origin;
	ray.iter = ray.origin;
	ray.angle = angle;
	return (ray);
}

static void	cast_ray_to_wall(t_ray *ray, t_game *game)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(ray->angle);
	sin_angle = sin(ray->angle);
	while (!touch(ray->iter.x, ray->iter.y, game))
	{
		ray->iter.x += cos_angle;
		ray->iter.y += sin_angle;
	}
	ray->hit.x = ray->iter.x;
	ray->hit.y = ray->iter.y;
}

static void	calculate_line_height(t_game *game, float dist, int *start_y, int *end_y)
{
	float	height;

	height = (BLOCK_SIZE / dist) * (0.5f * (float)game->window_width);
	*start_y = (game->window_height - height) / 2;
	*end_y = *start_y + height;
}

static void	draw_line(t_player *player, t_game *game, float start_x, int i)
{
	t_ray	ray;
	float	dist;
	int		start_y;
	int		end_y;

	ray = init_ray(player, start_x);
	cast_ray_to_wall(&ray, game);
	dist = fixed_dist(&ray, player->angle);
	calculate_line_height(game, dist, &start_y, &end_y);
	while (start_y < end_y)
	{
		put_pixel(i, start_y, 0xFFFFFF, game);
		start_y++;
	}
}

// draws a 3D raycast with all white walls
void	raycast(t_game *game, t_player *player)
{
	float	fraction;
	float	start_x;
	int		i;

	fraction = PI / 3 / game->window_width;
	start_x = player->angle - PI / 6;
	i = 0;
	while (i < game->window_width)
	{
		draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}
}
