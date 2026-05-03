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
	game->file.parser.no = malloc((sizeof(char) * len) + 1);
	if (!game->file.parser.no)
		return (1);
	ft_strlcpy(game->file.parser.no, &line[3], len + 1);
	return (0);
}

int	allocate_so(char *line, t_game *game)
{
	size_t	len;

	len = check_line(line, 0);
	if (len < 1)
		return (1);
	game->file.parser.so = malloc((sizeof(char) * len) + 1);
	if (!game->file.parser.so)
		return (1);
	ft_strlcpy(game->file.parser.so, &line[3], len + 1);
	return (0);
}

int	allocate_ea(char *line, t_game *game)
{
	size_t	len;

	len = check_line(line, 0);
	if (len < 1)
		return (1);
	game->file.parser.ea = malloc((sizeof(char) * len) + 1);
	if (!game->file.parser.ea)
		return (1);
	ft_strlcpy(game->file.parser.ea, &line[3], len + 1);
	return (0);
}

int	allocate_we(char *line, t_game *game)
{
	size_t	len;

	len = check_line(line, 0);
	if (len < 1)
		return (1);
	game->file.parser.we = malloc((sizeof(char) * len) + 1);
	if (!game->file.parser.we)
		return (1);
	ft_strlcpy(game->file.parser.we, &line[3], len + 1);
	return (0);
}
