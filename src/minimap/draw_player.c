/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:36:38 by tpirinen          #+#    #+#             */
/*   Updated: 2026/04/01 15:38:37 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(int x, int y, int size, int color, t_game *game)
{
	int	i;
	int	j;

	i = x - size;
	while (i <= x + size)
	{
		j = y - size;
		while (j <= y + size)
		{
			put_pixel(i, j, color, game);
			j++;
		}
		i++;
	}
}
