/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 01:40:54 by jtarvain          #+#    #+#             */
/*   Updated: 2026/04/30 11:36:14 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// example: "F 21,21,21"
//
// TODO
//
// safe long ft_atoi(const char *str)
//

static int	validate_format(char *line, t_game *game);

int	set_floor(char *line, t_game *game)
{
	if (!check_line(line))
		return (1);
	if (!validate_format(line, game))
		return (1);

	return (0);
}

int	set_ceiling(char *line, t_game *game)
{
	(void)line;
	(void)game;
	return (0);
}

static int	validate_format(char *line, t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 2;
	while ((line[i] && ft_isdigit(line[i])) && i < 5)
		i++;
	if (line[i] != ',')
		return (1);
	i++;
	j = 0;
	while ((line[i + j] && ft_isdigit(line[i + j])) && j < 3)
		j++;
	if (line[i + j] != ',')
		return (1);
	k = 0;
	while ((line[i + j + k] && ft_isdigit(line[i + j + k])) && k < 3)
		k++;
	game->file.parser.r_len = i - 2;
	game->file.parser.g_len = j;
	game->file.parser.b_len = k;
	return (0);
}
