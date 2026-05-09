/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:36:38 by tpirinen          #+#    #+#             */
/*   Updated: 2026/04/01 15:16:02 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_game *game, int size, int color, int x, int y)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(game, color, x + i, y);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(game, color, x, y + i);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(game, color, x + size, y + i);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(game, color, x + i, y + size);
		i++;
	}
}
