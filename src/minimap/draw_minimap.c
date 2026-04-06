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

void	draw_minimap(t_game *game)
{
	t_player	*player = &game->player;
	int			i;
	
	// draws a black rectangle to top left corner for minimap
	for (int i = 0; i < WIDTH / 4 - 7; i++){
		for (int j = 0; j < HEIGHT / 4 - 19; j++){
			put_pixel(i, j, 0x000000, game);
		}
	}
	
	// draws player onto minimap
	draw_player(player->x, player->y, 20, 0x00FF00, game);

	
	// Draws a set amount of rays into players FOV on minimap
	int		ray_count = 30;
	float	step;
	float	ray_angle;

	if (ray_count < 2)
		ray_count = 2;
	step = player->fov / (ray_count - 1);
	ray_angle = player->angle - (player->fov / 2.0f);
	i = 0;
	while (i < ray_count)
	{
		draw_line_map(player, game, ray_angle);
		ray_angle += step;
		i++;
	}

	draw_map(game);
}
