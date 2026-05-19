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
	uint32_t	ceiling;
	uint32_t	floor;
	uint32_t	*buf;
	size_t		total;
	size_t		i;

	ceiling = convert_rgb_to_hex(&game->config.c);
	floor = convert_rgb_to_hex(&game->config.f);
	buf = (uint32_t *)game->data;
	total = (size_t)game->window_width * (size_t)game->window_height;
	i = 0;
	while (i < total / 2)
	{
		buf[i] = ceiling;
		i++;
	}
	i = total / 2;
	while (i < total)
	{
		buf[i] = floor;
		i++;
	}
}
