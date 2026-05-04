/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 23:03:38 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/04 13:02:46 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_map(t_game *game)
{
	(void)game;
	// game->file.raw_map
	// 
	//
	// find width
	find_width(game);
	// find player position and angle
	//
	// malloc char **visited
	// 
	// flood fill map and fill visited
	return (0);
}

int	find_width(t_game *game)
{
	int	width;
	(void)width;
	int	i;

	width = 0;
	i = 0;
	while (game->file.raw_map[i])
	{
		printf("raw_map row: %i\n", i);
		i++;
	}
	return (0);
}


