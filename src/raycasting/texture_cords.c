/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:51:44 by tpirinen          #+#    #+#             */
/*   Updated: 2026/04/01 15:37:07 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_x(t_game *game, int orientation)
{
	int	texture_x;

	if (game->ray.hit == VERTICAL)
		texture_x = (int)game->ray.y % BLOCK_SIZE;
	if (game->ray.hit == HORIZONTAL)
		texture_x = (int)game->ray.x % BLOCK_SIZE;
	if (orientation == NO || orientation == EA)
		texture_x = BLOCK_SIZE - texture_x - 1;
	return (texture_x);
}

int	get_texture_y(int current_y, int wall_top, float height)
{
	int	texture_y;

	texture_y = (int)((float)(current_y - wall_top)
			/ height * BLOCK_SIZE);
	if (texture_y < 0)
		texture_y = 0;
	if (texture_y >= BLOCK_SIZE)
		texture_y = BLOCK_SIZE - 1;
	return (texture_y);
}
