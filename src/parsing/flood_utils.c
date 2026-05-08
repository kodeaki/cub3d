/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:27:37 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/08 15:03:34 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	allocate_visited(t_game *game)
{
	int	i;

	i = 0;
	game->map.visited = malloc(sizeof(int *) * (game->map.height + 1));
	if (!game->map.visited)
		return (1);
	game->map.visited[game->map.height] = NULL;
	while (i < game->map.height)
	{
		game->map.visited[i] = ft_calloc(game->map.width, sizeof(int));
		if (!game->map.visited[i])
			return (free_mapc(game->map.visited, i), 1);
		i++;
	}
	return (0);
}
