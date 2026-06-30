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

void	open_file(int argc, char **argv, t_game *game)
{
	int	fd;

	if (argc != 2)
		ft_exit(game, ERR_ARGC);
	if (!argv[1][0])
		ft_exit(game, ERR_FILE_NAME_EMPTY);
	if (check_extension(argv[1]))
		ft_exit(game, ERR_FILE_NAME_EXTENSION);
	fd = open(argv[1], O_RDONLY, 0);
	if (fd < 0)
		ft_exit(game, ERR_FILE_OPEN);
	game->file.line_count = parse_file(fd, game);
	if (ft_check(game))
	{
		close(fd);
		ft_exit(game, ERR_FILE_INVALID_LINE);
	}
	close(fd);
}

int	parse_file(int fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	i = 0;
	if (!line)
		ft_exit(game, ERR_FILE_EMPTY);
	while (line)
	{
		if (process_line(game, line, i))
		{
			free(line);
			ft_exit(game, ERR_FILE_INVALID_LINE);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
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
		return (add_check(game, line), 0);
	else
	
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
