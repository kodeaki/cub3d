/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:27:36 by tpirinen          #+#    #+#             */
/*   Updated: 2026/05/12 16:54:10 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_init_steps(t_game *game)
{
	if (game->ray.dir.x < 0.0)
	{
		game->ray.step_x = -1;
		game->ray.sidedist_x = (game->player.pos.x - game->ray.map_x)
			* game->ray.deltadist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.sidedist_x = (game->ray.map_x + 1.0 - game->player.pos.x)
			* game->ray.deltadist_x;
	}
	if (game->ray.dir.y < 0.0)
	{
		game->ray.step_y = -1;
		game->ray.sidedist_y = (game->player.pos.y - game->ray.map_y)
			* game->ray.deltadist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.sidedist_y = (game->ray.map_y + 1.0 - game->player.pos.y)
			* game->ray.deltadist_y;
	}
}

void	ray_init(t_game *game, int col)
{
	double	camera_x;

	camera_x = 2.0 * col / (double)game->window_width - 1.0;
	game->ray.dir.x = game->player.dir.x
		+ (game->player.plane.x * camera_x);
	game->ray.dir.y = game->player.dir.y
		+ (game->player.plane.y * camera_x);
	game->ray.map_x = (int)game->player.pos.x;
	game->ray.map_y = (int)game->player.pos.y;
	game->ray.screen_x = col;
	if (game->ray.dir.x == 0.0)
		game->ray.deltadist_x = 1e30;
	else
		game->ray.deltadist_x = fabs(1.0 / game->ray.dir.x);
	if (game->ray.dir.y == 0.0)
		game->ray.deltadist_y = 1e30;
	else
		game->ray.deltadist_y = fabs(1.0 / game->ray.dir.y);
	game->ray.hit = false;
	ray_init_steps(game);
}
