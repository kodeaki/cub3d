/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:53:01 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/06 23:15:04 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flood_fill(t_game *game)
{
	int	y;
	int	x;

	y = game->file.parser.player_y;
	x = game->file.parser.player_x;
	if (allocate_visited(game))
		return (1);
	fill(game, game->map.visited, y, x);
	if (compare(game, game->map.arr, game->map.visited))
		return (free_mapc(game->map.visited, game->map.height), 1);
	free_mapc(game->map.visited, game->map.height);
	return (0);
}

void	fill(t_game *game, int **visited, int y, int x)
{
	if (y < 0 || y >= game->map.height || x < 0 || x >= game->map.width)
		return ;
	if (game->map.arr[y][x] == '1')
		return ;
	if (visited[y][x] == 1)
		return ;
	visited[y][x] = 1;
	fill(game, visited, y + 1, x);
	fill(game, visited, y - 1, x);
	fill(game, visited, y, x + 1);
	fill(game, visited, y, x - 1);
	fill(game, visited, y + 1, x - 1);
	fill(game, visited, y + 1, x + 1);
	fill(game, visited, y - 1, x - 1);
	fill(game, visited, y - 1, x + 1);
	return ;
}

int	compare(t_game *game, char **map, int **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if ((map[i][j] == '1' || map[i][j] == ' ')
					&& visited[i][j] == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
