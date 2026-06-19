/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:39:23 by jtarvain          #+#    #+#             */
/*   Updated: 2026/06/09 01:39:16 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->window_width - 1)
	{
		ray_init(game, x);
		ray_dda(game);
		test_dda(game);
		x++;
	}
}
