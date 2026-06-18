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

void	ray_init(t_game *game, int col)
{
	double	camera_x;

	camera_x = 2.0 * col / (double)game->window_width - 1.0;
	game->ray.ray_dir.x = game->player.dir.x + (game->player.plane.x * camera_x);
	game->ray.ray_dir.y = game->player.dir.y + (game->player.plane.y * camera_x);
	game->ray.map_x = (int)game->player.pos.x;
	game->ray.map_y = (int)game->player.pos.y;
	if (game->ray.ray_dir.x == 0.0)
		game->ray.deltadist_x = 1e30;
	else
		game->ray.deltadist_x = fabs(1.0 / game->ray.ray_dir.x);
	if (game->ray.ray_dir.y == 0.0)
		game->ray.deltadist_y = 1e30;
	else
		game->ray.deltadist_y = fabs(1.0 / game->ray.ray_dir.y);
	game->ray.hit = false;
	ray_init_steps(game);
}
