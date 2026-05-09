/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:14:39 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/04 14:09:29 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

/*
 *	Main parsing logic
 *  --------------------
 *  First time opening going through line by line, getting us:
 *  - line count
 *  - map start
 *  - valitating that map is last
 *  - validating that only once NO SO EA WE F C
 *  - no mallocs
 *
 *  Second time opening going through line by line, gets us:
 *  - NO SO EA WE F C strings - malloc
 *  - 2d game map malloced
 *  - validating that each string is legit
 * 111
 * 1N1
 * 111
 *
 *  Third part of parsing
 *  - validating map
 *  	floodfill
 *  	min - max validation on width
 *
 */
int	parsing(int argc, char **argv, t_game *game)
{
	if (open_file(argc, argv, game))
		return (1);
	printf("Parsing info start\n");
	printf("Map line start: %i\n", game->file.map_start);
	printf("Map rows: %i\n", game->file.line_count - game->file.map_start);
	if (set_height(game))
		return (1);
	if (copy_file(argv, game))
		return (1);
	print_parser(game);
	if (parse_map(game))
		return (1);
	return (0);
}

void	print_parser(t_game *game)
{
	printf("no texture: %s\n", game->config.north.path);
	printf("so texture: %s\n", game->config.south.path);
	printf("we texture: %s\n", game->config.west.path);
	printf("ea texture: %s\n", game->config.east.path);
}
