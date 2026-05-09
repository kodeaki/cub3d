/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:56:24 by tpirinen          #+#    #+#             */
/*   Updated: 2026/04/01 15:26:58 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_square(t_game *game, int size, int x, int y)
{
	int	color;
	int	i;

	color = 0xFFFFFF;
	i = -1;
	while (++i < size)
		put_pixel(game, color, x + i, y);
	i = -1;
	while (++i < size)
		put_pixel(game, color, x, y + i);
	i = -1;
	while (++i < size)
		put_pixel(game, color, x + size, y + i);
	i = -1;
	while (++i < size)
		put_pixel(game, color, x + i, y + size);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.arr[y])
	{
		x = 0;
		while (game->map.arr[y][x])
		{
			if (game->map.arr[y][x] == '1')
				draw_square(game, game->minimap.cell,
					x * game->minimap.cell,
					y * game->minimap.cell);
			x++;
		}
		y++;
	}
}
