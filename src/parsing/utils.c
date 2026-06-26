/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:24:28 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/06 23:27:06 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_height(t_game *game)
{
	int	height;

	height = game->file.line_count - game->file.map_start;
	if (height < 3)
		return (1);
	game->map.height = height;
	return (0);
}

void	ft_exit(int err, const char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	exit(err);
}

int	ft_close(int fd, int ret)
{
	close(fd);
	return (ret);
}
