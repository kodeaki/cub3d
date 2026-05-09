/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 00:20:34 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/03 22:57:41 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	allocate_no(char *line, t_game *game)
{
	size_t	len;

	len = check_line(line, 0);
	if (len < 1)
		return (1);
	game->config.north.path = malloc((sizeof(char) * len) + 1);
	if (!game->config.north.path)
		return (1);
	ft_strlcpy(game->config.north.path, &line[3], len + 1);
	return (0);
}

int	allocate_so(char *line, t_game *game)
{
	size_t	len;

	len = check_line(line, 0);
	if (len < 1)
		return (1);
	game->config.south.path = malloc((sizeof(char) * len) + 1);
	if (!game->config.south.path)
		return (1);
	ft_strlcpy(game->config.south.path, &line[3], len + 1);
	return (0);
}

int	allocate_ea(char *line, t_game *game)
{
	size_t	len;

	len = check_line(line, 0);
	if (len < 1)
		return (1);
	game->config.east.path = malloc((sizeof(char) * len) + 1);
	if (!game->config.east.path)
		return (1);
	ft_strlcpy(game->config.east.path, &line[3], len + 1);
	return (0);
}

int	allocate_we(char *line, t_game *game)
{
	size_t	len;

	len = check_line(line, 0);
	if (len < 1)
		return (1);
	game->config.west.path = malloc((sizeof(char) * len) + 1);
	if (!game->config.west.path)
		return (1);
	ft_strlcpy(game->config.west.path, &line[3], len + 1);
	return (0);
}
