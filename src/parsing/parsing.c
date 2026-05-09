/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:14:39 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/09 18:23:59 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	parsing(int argc, char **argv, t_game *game)
{
	if (open_file(argc, argv, game))
		return (1);
	if (set_height(game))
		return (1);
	if (copy_file(argv, game))
		return (1);
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
