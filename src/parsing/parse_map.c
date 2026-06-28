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

void	parse_map(t_game *game)
{
	scan_map(game);
	copy_map(game);
	flood_fill(game);
}

void	scan_map(t_game *game)
{
	int	i;
	int	longest_row;
	int	w;

	i = 0;
	longest_row = 0;
	while (game->file.raw_map[i])
	{
		w = row_width(game, game->file.raw_map[i], i);
		if (longest_row < w)
			longest_row = w;
		i++;
	}
	if (longest_row < 3)
		ft_exit(game, ERR_NARROW_MAP);
	if (game->file.parser.player_count != 1)
		ft_exit(game, ERR_PLAYER_COUNT);
	game->map.width = longest_row;
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
