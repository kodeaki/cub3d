/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 01:40:54 by jtarvain          #+#    #+#             */
/*   Updated: 2026/06/26 13:41:59 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	count_digits(char *line, size_t *i);
static int		validate_format(char *line, t_game *game, size_t start);
static uint32_t	convert_rgb_to_hex(t_rgb *rgb);

int	set_floor(char *line, t_game *game)
{
	size_t	pos;

	if (!check_line(line, 1))
		return (1);
	pos = 2;
	while (line[pos] && ft_space(line[pos]) && line[pos] != '\n')
		pos++;
	if (validate_format(line, game, pos))
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
	pos = 2;
	while (line[pos] && ft_space(line[pos]) && line[pos] != '\n')
		pos++;
	if (validate_format(line, game, pos))
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

static size_t	count_digits(char *line, size_t *i)
{
	size_t	count;

	count = 0;
	while (line[*i] && ft_isdigit(line[*i]) && count < 3)
	{
		(*i)++;
		count++;
	}
	return (count);
}

static int	validate_format(char *line, t_game *game, size_t start)
{
	size_t	i;

	i = start;
	game->file.parser.r_len = count_digits(line, &i);
	if (!game->file.parser.r_len || line[i++] != ',')
		return (1);
	game->file.parser.g_len = count_digits(line, &i);
	if (!game->file.parser.g_len || line[i++] != ',')
		return (1);
	game->file.parser.b_len = count_digits(line, &i);
	if (!game->file.parser.b_len || no_trailing_content(&line[i]))
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
