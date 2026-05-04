/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:24:28 by jtarvain          #+#    #+#             */
/*   Updated: 2026/04/30 11:33:09 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_height(t_game *game)
{
	int	height;

	height = game->file.line_count - game->file.map_start;
	if (height < 3)
		return (1);
	return (0);
}

void	ft_exit(int	err, const char *msg)
{
	printf("Error.\n");
	printf("%s\n", msg);
	exit(err);
}

int		ft_close(int fd, int ret)
{
	close(fd);
	return (ret);
}

void	ft_free(t_game *game)
{
	if (game->file.parser.no)
		free(game->file.parser.no);
	if (game->file.parser.so)
		free(game->file.parser.no);
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
