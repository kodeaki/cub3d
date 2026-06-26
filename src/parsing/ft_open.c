/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 09:07:49 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/06 23:24:14 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_file(int argc, char **argv, t_game *game)
{
	int	fd;

	if (argc != 2 || !argv[1][0])
		return (1);
	if (check_extension(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY, 0);
	if (fd < 0)
		return (ft_close(fd, 1));
	game->file.line_count = parse_file(fd, game);
	if (!game->file.line_count)
		return (ft_close(fd, 1));
	if (ft_check(game))
		return (ft_close(fd, 1));
	return (ft_close(fd, 0));
}

int	parse_file(int fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	i = 0;
	if (!line)
		return (0);
	while (line)
	{
		if (process_line(game, line, i))
			return (free(line), 0);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
	return (i);
}

int	process_line(t_game *game, char *line, int i)
{
	if (!ft_strset(line, "10NSEW ") && !game->file.map_start)
	{
		if (empty_row(line))
			return (game->file.map_start = i, 0);
	}
	if (!ft_strset(line, "10NSEW "))
	{
		if (game->file.map_start && !empty_row(line))
			return (1);
		return (0);
	}
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3)
		|| !ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
	{
		add_check(game, line);
		return (0);
	}
	if (game->file.map_start && empty_row(line))
		return (1);
	if (empty_row(line))
		return (0);
	return (1);
}

int	check_extension(char *file)
{
	char	*last_dot;

	last_dot = ft_strrchr(file, '.');
	if (!last_dot)
		return (1);
	if (ft_strncmp(last_dot, ".cub", 5))
		return (1);
	return (0);
}

int	add_check(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		game->file.check.no++;
	else if (!ft_strncmp(line, "SO ", 3))
		game->file.check.so++;
	else if (!ft_strncmp(line, "EA ", 3))
		game->file.check.ea++;
	else if (!ft_strncmp(line, "WE ", 3))
		game->file.check.we++;
	else if (!ft_strncmp(line, "C ", 2))
		game->file.check.c++;
	else if (!ft_strncmp(line, "F ", 2))
		game->file.check.f++;
	return (0);
}
