/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:53:01 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/06 15:56:12 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flood_fill(t_game *game)
{
	if (allocate_visited(game))
		return (1);
	free_mapc(game->map.visited, game->map.height);
	return (0);
}

int	fill(char **map, int **visited)
{
	(void)map;
	(void)visited;
	return (0);
}
