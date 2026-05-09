/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:27:36 by tpirinen          #+#    #+#             */
/*   Updated: 2026/03/31 15:34:47 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	convert_rgb_to_hex(t_rgb *rgb)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = (uint32_t)rgb->r;
	g = (uint32_t)rgb->g;
	b = (uint32_t)rgb->b;
	return (r << 16 | g << 8 | b);
}

// Clears old frame by painting the top half with the ceiling color
// and the bottom half with the floor color
void	clear_image(t_game *game)
{
	int	y;
	int	x;
	uint32_t	ceiling;
	uint32_t	floor;

	ceiling = convert_rgb_to_hex(&game->config.c);
	floor = convert_rgb_to_hex(&game->config.f);
	y = 0;
	while (y < game->window_height / 2)
	{
		x = 0;
		while (x < game->window_width)
			put_pixel(game, ceiling, x++, y);
		y++;
	}
	while (y < game->window_height)
	{
		x = 0;
		while (x < game->window_width)
			put_pixel(game, floor, x++, y);
		y++;
	}
}
