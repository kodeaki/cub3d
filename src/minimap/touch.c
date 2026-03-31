/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:42:24 by tpirinen          #+#    #+#             */
/*   Updated: 2026/03/31 16:45:51 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK_SIZE;
	y = py / BLOCK_SIZE;
	if (game->map.arr[y][x] == '1')
		return (true);
	return (false);
}