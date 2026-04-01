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

	i = 0;
	while (i < size)
	{
		put_pixel((x + i) / 4 - 3, y / 4 - 3, color, game);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(x / 4 - 3, (y + i) / 4 - 3, color, game);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel((x + size) / 4 - 3, (y + i) / 4 - 3, color, game);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel((x + i) / 4 - 3, (y + size) / 4 - 3, color, game);
		i++;
	}
}
