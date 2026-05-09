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

static int	texture_to_color(t_texture *texture, int texture_x, int texture_y)
{
	int	index;
	int	color;

	if (!texture->data)
		return (0);
	if (texture_x < 0 || texture_x >= BLOCK_SIZE
		|| texture_y < 0 || texture_y >= BLOCK_SIZE)
		return (0);
	index = (texture_y * texture->size_line) + (texture_x * (texture->bpp / 8));
	color = *(unsigned int *)(texture->data + index);
	return (color);
}

static t_texture	*select_texture(t_game *game, int orientation)
{
	if (orientation == NO)
		return (&game->config.north);
	if (orientation == SO)
		return (&game->config.south);
	if (orientation == EA)
		return (&game->config.east);
	if (orientation == WE)
		return (&game->config.west);
	return (NULL);
}

static int	get_orientation(t_game *game)
{
	if (game->ray.hit == VERTICAL)
	{
		if (game->ray.cos_angle > 0)
			return (EA);
		else
			return (WE);
	}
	else
	{
		if (game->ray.sin_angle > 0)
			return (SO);
		else
			return (NO);
	}
}

int	get_texture_color(t_game *game, int current_y,
				int wall_top, float height)
{
	int			orientation;
	t_texture	*texture;
	int			texture_x;
	int			texture_y;
	int			color;

	orientation = get_orientation(game);
	texture = select_texture(game, orientation);
	if (texture == NULL || texture->data == NULL)
		return (0);
	texture_x = get_texture_x(game, orientation);
	texture_y = get_texture_y(current_y, wall_top, height);
	color = texture_to_color(texture, texture_x, texture_y);
	return (color);
}
