/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 01:40:54 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/02 19:29:20 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// example: "F 21,21,21"
//
// TODO
//
// safe long ft_atoi(const char *str)
//
// populate struct t_rgb

static int	validate_format(char *line, t_game *game);
static int	check_rgb_lens(t_game *game);

int	set_floor(char *line, t_game *game)
{
	size_t	pos;

	if (!check_line(line))
		return (1);
	if (validate_format(line, game))
		return (1);
	pos = 2;
	if (check_rgb_lens(game))
		return (1);
	if (set_color(&line[pos], &game->config.f.r, game->file.parser.r_len))
		return (1);
	pos = pos + game->file.parser.r_len + 1;
	if (set_color(&line[pos], &game->config.f.g, game->file.parser.g_len))
		return (1);
	pos = pos + game->file.parser.g_len + 1;
	if (set_color(&line[pos], &game->config.f.b, game->file.parser.b_len))
		return (1);
	return (0);
}

int	set_ceiling(char *line, t_game *game)
{
	size_t	pos;

	if (!check_line(line))
		return (1);
	if (validate_format(line, game))
		return (1);
	pos = 2;
	if (check_rgb_lens(game))
		return (1);
	if (set_color(&line[pos], &game->config.c.r, game->file.parser.r_len))
		return (1);
	pos = pos + game->file.parser.r_len + 1;
	if (set_color(&line[pos], &game->config.c.g, game->file.parser.g_len))
		return (1);
	pos = pos + game->file.parser.g_len + 1;
	if (set_color(&line[pos], &game->config.c.b, game->file.parser.b_len))
		return (1);
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
	if (line[i++] != ',')
		return (1);
	j = 0;
	while ((line[i + j] && ft_isdigit(line[i + j])) && j < 3)
		j++;
	if (line[i + j++] != ',')
		return (1);
	k = 0;
	while ((line[i + j + k] && ft_isdigit(line[i + j + k])) && k < 3)
		k++;
	game->file.parser.r_len = i - 3;
	game->file.parser.g_len = j - 1;
	game->file.parser.b_len = k;
	return (0);
}

static int	check_rgb_lens(t_game *game)
{
	if (!game->file.parser.r_len || !game->file.parser.g_len ||
			!game->file.parser.b_len)
		return (1);
	if (game->file.parser.r_len > 3 || game->file.parser.g_len > 3 ||
			game->file.parser.b_len > 3)
		return (1);
	return (0);

}
