/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:36:38 by tpirinen          #+#    #+#             */
/*   Updated: 2026/04/01 15:38:37 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_game *game, int size, int color)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = (int)((game->player.pos.x / BLOCK_SIZE) * game->minimap.cell);
	y = (int)((game->player.pos.y / BLOCK_SIZE) * game->minimap.cell);
	i = x - size;
	while (i <= x + size)
	{
		j = y - size;
		while (j <= y + size)
		{
			put_pixel(game, color, i, j);
			j++;
		}
		i++;
	}
}
