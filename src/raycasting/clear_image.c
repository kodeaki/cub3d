/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:27:36 by tpirinen          #+#    #+#             */
/*   Updated: 2026/06/28 10:55:44 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Clears old frame by painting the top half with the ceiling color
// and the bottom half with the floor color
void	clear_image(t_game *game)
{
	uint32_t	*buf;
	uint32_t	*mid;
	uint32_t	*end;
	size_t		total;

	buf = (uint32_t *)game->data;
	total = (size_t)game->window_width * (size_t)game->window_height;
	mid = buf + total / 2;
	end = buf + total;
	while (buf < mid)
		*buf++ = game->config.ceiling;
	while (buf < end)
		*buf++ = game->config.floor;
}
