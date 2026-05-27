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
	if (scan_map(game))
		return (ft_free(game), 1);
	if (copy_map(game))
		return (ft_free(game), 1);
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

void	store_player_orientation(t_game *game, char orientation)
{
	if (orientation == 'N')
		game->file.parser.orientation = NO;
	else if (orientation == 'S')
		game->file.parser.orientation = SO;
	else if (orientation == 'E')
		game->file.parser.orientation = EA;
	else if (orientation == 'W')
		game->file.parser.orientation = WE;
}

int	row_width(t_game *game, const char *row, const int y)
{
	int	i;
	int	last_wall;

	i = 0;
	last_wall = 0;
	while (row[i])
	{
		if (row[i] == '1')
			last_wall = i + 1;
		if (row[i] == 'N' || row[i] == 'S' || row[i] == 'E'
			|| row[i] == 'W')
		{
			store_player_orientation(game, row[i]);
			game->file.parser.player_x = i;
			game->file.parser.player_y = y;
			game->file.parser.player_count++;
		}
		i++;
	}
	return (last_wall);
}
