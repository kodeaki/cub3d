/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:42:24 by tpirinen          #+#    #+#             */
/*   Updated: 2026/04/01 15:34:11 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	touch(t_game *game, double px, double py)
{
	int	x;
	int	y;

	x = px / BLOCK_SIZE;
	y = py / BLOCK_SIZE;
	if (x < 0 || y < 0)
		return (true);
	if (x >= game->map.width || y >= game->map.height)
		return (true);
	if (game->map.arr[y][x] == '1'
		|| game->map.arr[y][x] == ' ')
		return (true);
	return (false);
}
