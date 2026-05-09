/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:00:28 by tpirinen          #+#    #+#             */
/*   Updated: 2026/04/01 15:40:08 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void draw_minimap_background(t_game *game)
{
	int		x;
	int		y;

	game->minimap.width = game->map.width * game->minimap.cell;
	game->minimap.height = game->map.height * game->minimap.cell;
	x = 0;
	while (x < game->minimap.width)
	{
		y = 0;
		while (y < game->minimap.height)
		{
			put_pixel(game, 0x000000, x, y);
			y++;
		}
		x++;
	}
}

// Clears minimap with a black rectangle, draws rays, player, and map
void	draw_minimap(t_game *game)
{
	game->minimap.cell = (int)(game->window_width / 4) / game->map.width;
	draw_minimap_background(game);
	draw_rays(&game->player, game);
	draw_player(game, 0x00FF00,
		(int)((game->player.x / BLOCK_SIZE) * game->minimap.cell),
		(int)((game->player.y / BLOCK_SIZE) * game->minimap.cell),
		game->minimap.cell / 4);
	draw_map(game);
}
