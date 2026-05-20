/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 01:40:54 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/06 23:19:47 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		validate_format(char *line, t_game *game);
static int		check_rgb_len(t_game *game);
static uint32_t	convert_rgb_to_hex(t_rgb *rgb);

int	set_floor(char *line, t_game *game)
{
	size_t	pos;

	if (!check_line(line, 1))
		return (1);
	if (validate_format(line, game))
		return (1);
	pos = 2;
	if (check_rgb_len(game))
		return (1);
	if (set_color(&line[pos], &game->file.parser.f.r, game->file.parser.r_len))
		return (1);
	pos = pos + game->file.parser.r_len + 1;
	if (set_color(&line[pos], &game->file.parser.f.g, game->file.parser.g_len))
		return (1);
	pos = pos + game->file.parser.g_len + 1;
	if (set_color(&line[pos], &game->file.parser.f.b, game->file.parser.b_len))
		return (1);
	game->config.floor = convert_rgb_to_hex(&game->file.parser.f);
	return (0);
}

int	set_ceiling(char *line, t_game *game)
{
	size_t	pos;

	if (!check_line(line, 1))
		return (1);
	if (validate_format(line, game))
		return (1);
	pos = 2;
	if (check_rgb_len(game))
		return (1);
	if (set_color(&line[pos], &game->file.parser.c.r, game->file.parser.r_len))
		return (1);
	pos = pos + game->file.parser.r_len + 1;
	if (set_color(&line[pos], &game->file.parser.c.g, game->file.parser.g_len))
		return (1);
	pos = pos + game->file.parser.g_len + 1;
	if (set_color(&line[pos], &game->file.parser.c.b, game->file.parser.b_len))
		return (1);
	game->config.ceiling = convert_rgb_to_hex(&game->file.parser.c);
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

static int	check_rgb_len(t_game *game)
{
	if (!game->file.parser.r_len || !game->file.parser.g_len
		|| !game->file.parser.b_len)
		return (1);
	if (game->file.parser.r_len > 3 || game->file.parser.g_len > 3
		|| game->file.parser.b_len > 3)
		return (1);
	return (0);
}

static uint32_t	convert_rgb_to_hex(t_rgb *rgb)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = (uint32_t)rgb->r;
	g = (uint32_t)rgb->g;
	b = (uint32_t)rgb->b;
	return (r << 16 | g << 8 | b);
}
