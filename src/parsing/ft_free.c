/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:22:54 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/03 19:28:47 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(t_game *game)
{
	if (game->file.parser.no)
		free(game->file.parser.no);
	if (game->file.parser.so)
		free(game->file.parser.so);
	if (game->file.parser.ea)
		free(game->file.parser.ea);
	if (game->file.parser.we)
		free(game->file.parser.we);
	if (game->file.raw_map)
		free_map(game->file.raw_map);
	if (game->map.arr)
		free_map(game->map.arr);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
