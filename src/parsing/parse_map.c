/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 23:03:38 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/06 15:58:21 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_map(t_game *game)
{
	// scan through the map, finding:
	// player position & width
	printf("parse_map enter\n");
	if (scan_map(game))
		return (ft_free(game), 1);
	// allocate map 2d array and fill
	printf("game width: %i\n", game->map.width);
	if (copy_map(game))
		return (ft_free(game), 1);
	// flood fill with visited 2d array
	if (flood_fill(game))
		return (1);
	return (0);
}

int	scan_map(t_game *game)
{
	int	i;
	int	longest_row;

	i = 0;
	longest_row = 0;
	while (game->file.raw_map[i])
	{
		if (longest_row < row_width(game, game->file.raw_map[i], i))
			longest_row = row_width(game, game->file.raw_map[i], i);
		i++;
	}
	if (longest_row < 3)
		return (1);
	if (game->file.parser.player_count != 1)
		return (1);
	game->map.width = longest_row;
	return (0);
}

int	row_width(t_game *game, const char *row, const int y)
{
	int	i;
	int	last_wall;

	i = 0;
	while (row[i])
	{
		if (row[i] == '1')
			last_wall = i + 1;
		if (row[i] == 'N' || row[i] == 'S' || row[i] == 'E'
				|| row[i] == 'W')
		{
			game->file.parser.player_x = i;
			game->file.parser.player_y = y;
			game->file.parser.player_count++;
		}
		i++;
	}
	return (last_wall);
}
