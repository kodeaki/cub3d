/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:27:36 by tpirinen          #+#    #+#             */
/*   Updated: 2026/06/24 17:32:30 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_perp_dist(t_game *game)
{
	if (game->ray.side == X_SIDE)
		game->ray.perp_dist = game->ray.sidedist_x - game->ray.deltadist_x;
	else if (game->ray.side == Y_SIDE)
		game->ray.perp_dist = game->ray.sidedist_y - game->ray.deltadist_y;
	if (game->ray.perp_dist <= 0.0)
		game->ray.perp_dist = 1e-6;
}

static void	calculate_texture_u(t_game *game)
{
	if (game->ray.side == X_SIDE)
	{
		game->ray.texture_u = game->player.pos.y
			+ (game->ray.perp_dist * game->ray.dir.y);
		if (game->ray.step_x == -1)
			game->ray.texture_u = 1.0 - game->ray.texture_u;
	}
	else if (game->ray.side == Y_SIDE)
	{
		game->ray.texture_u = game->player.pos.x
			+ (game->ray.perp_dist * game->ray.dir.x);
		if (game->ray.step_y == 1)
			game->ray.texture_u = 1.0 - game->ray.texture_u;
	}
	game->ray.texture_u -= floor(game->ray.texture_u);
}

void	texture_setup(t_game *game)
{
	t_texture	*texture;

	calculate_perp_dist(game);
	calculate_texture_u(game);
	texture = get_wall_texture(game);
	game->ray.texture_x = (int)(game->ray.texture_u * texture->width);
	if (game->ray.texture_x >= texture->width)
		game->ray.texture_x = texture->width - 1;
	game->ray.line_height = (int)(game->window_height / game->ray.perp_dist);
	game->ray.texture_step = (double)texture->height / game->ray.line_height;
}
