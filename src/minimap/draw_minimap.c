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

static void	draw_minimap_background(t_game *game)
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
	int	cell_w;
	int	cell_h;

	cell_w = (game->window_width / 3) / game->map.width;
	cell_h = (game->window_height / 3) / game->map.height;
	if (cell_w < cell_h)
		game->minimap.cell = cell_w;
	else
		game->minimap.cell = cell_h / 2;
	if (game->minimap.cell < 1)
		game->minimap.cell = 1;
	draw_minimap_background(game);
	draw_rays(&game->player, game);
	draw_player(game, game->minimap.cell / 4, 0x00FF00);
	draw_map(game);
}
