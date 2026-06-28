/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:27:36 by tpirinen          #+#    #+#             */
/*   Updated: 2026/06/28 10:55:39 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_wall_texture(t_game *game)
{
	if (game->ray.side == X_SIDE)
	{
		if (game->ray.step_x == 1)
			return (&game->config.east);
		else
			return (&game->config.west);
	}
	else
	{
		if (game->ray.step_y == 1)
			return (&game->config.south);
		else
			return (&game->config.north);
	}
}
