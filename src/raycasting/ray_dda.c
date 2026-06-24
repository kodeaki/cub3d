/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:27:36 by tpirinen          #+#    #+#             */
/*   Updated: 2026/05/12 16:54:10 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_dda(t_game *game)
{
	while (!game->ray.hit)
	{
		if (game->ray.sidedist_x < game->ray.sidedist_y)
		{
			game->ray.sidedist_x += game->ray.deltadist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = X_SIDE;
		}
		else
		{
			game->ray.sidedist_y += game->ray.deltadist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = Y_SIDE;
		}
		if (game->ray.map_x < 0 || game->ray.map_y < 0
			|| game->ray.map_x >= game->map.width
			|| game->ray.map_y >= game->map.height)
		{
			game->ray.hit = true;
			break ;
		}
		if (game->map.arr[game->ray.map_y][game->ray.map_x] == '1'
			|| game->map.arr[game->ray.map_y][game->ray.map_x] == ' ')
			game->ray.hit = true;
	}
}
