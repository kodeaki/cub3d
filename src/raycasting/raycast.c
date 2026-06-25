/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:39:23 by jtarvain          #+#    #+#             */
/*   Updated: 2026/06/24 19:24:16 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_game *game)
{
	uint32_t	*data;
	int			x;

	data = (uint32_t *)game->data;
	x = 0;
	while (x < game->window_width - 1)
	{
		ray_init(game, x);
		ray_dda(game);
		texture_setup(game);
		draw_column(game, data);
		x++;
	}
}
