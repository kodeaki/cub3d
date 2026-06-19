/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:36:38 by tpirinen          #+#    #+#             */
/*   Updated: 2026/03/31 14:37:34 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	touch(t_game *game, double px, double py)
{
	int		map_x;
	int		map_y;
	char	cell;

	if (px < 0.0 || py < 0.0)
		return (true);
	map_x = (int)px;
	map_y = (int)py;
	if (map_y < 0 || map_y >= game->map.height
		|| map_x < 0 || map_x >= game->map.width)
		return (true);
	cell = game->map.arr[map_y][map_x];
	if (cell == '1' || cell == ' ')
		return (true);
	return (false);
}
