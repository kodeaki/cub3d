/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:39:23 by jtarvain          #+#    #+#             */
/*   Updated: 2026/06/28 10:55:30 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_game *game)
{
	uint32_t	*data;
	int			col;

	data = (uint32_t *)game->data;
	col = 0;
	while (col < game->window_width - 1)
	{
		ray_init(game, col);
		ray_dda(game);
		texture_setup(game);
		draw_column(game, data);
		col++;
	}
}
