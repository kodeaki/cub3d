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

void	set_height(t_game *game)
{
	int	height;

	height = game->file.line_count - game->file.map_start;
	if (height < 3)
		ft_exit(game, ERR_FILE_INVALID_MAP);
	game->map.height = height;
}

void	ft_exit(t_game *game, const char *msg)
{
	if (game)
		ft_free(game);
	printf("Error\n");
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
