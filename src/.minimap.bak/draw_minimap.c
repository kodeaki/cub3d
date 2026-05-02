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

// Clears minimap with a black rectangle, draws rays, player, and map
void	draw_minimap(t_game *game)
{
	t_player	*player;
	int			i;
	int			j;

	player = &game->player;
	i = 0;
	while (i < WIDTH / 4 - 7)
	{
		j = 0;
		while (j < HEIGHT / 4 - 19)
		{
			put_pixel(i, j, 0x000000, game);
			j++;
		}
		i++;
	}
	draw_rays(player, game);
	draw_player(player->x, player->y, 20, 0x00FF00, game);
	draw_map(game);
}
