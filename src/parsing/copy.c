/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:47:01 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/06 11:25:31 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_file(char **argv, t_game *game)
{
	int	fd;
	int	map_size;

	map_size = game->file.line_count - game->file.map_start;
	fd = open(argv[1], O_RDONLY, 0);
	if (fd < 0)
		ft_exit(game, ERR_FILE_OPEN);
	game->file.raw_map = ft_calloc(map_size + 1, sizeof(char *));
	if (!game->file.raw_map)
	{
		close(fd);
		ft_exit(game, ERR_MEMORY_ALLOC);
	}
	if (get_elements(fd, game))
	{
		close(fd);
		ft_exit(game, ERR_FILE_ELEMENTS);
	}
	close(fd);
}

int	get_elements(int fd, t_game *game)
{
	volatile int	i;
	char			*line;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line && i < game->file.map_start)
	{
		if (loading(fd, &i, &line, game))
			return (1);
	}
	if (loading_map(fd, &line, game))
		return (1);
	if (line)
		free(line);
	return (0);
}

int	loading(int fd, volatile int *i, char **line, t_game *game)
{
	if (load_line(*line, game))
		return (free(*line), 1);
	free(*line);
	*line = get_next_line(fd);
	if (!*line)
		return (1);
	(*i)++;
	return (0);
}

int	loading_map(int fd, char **line, t_game *game)
{
	int	i;

	i = 0;
	errno = 0;
	game->file.raw_map[i] = ft_strdup(*line);
	if (!game->file.raw_map[i++])
		return (free(*line), 1);
	while (*line)
	{
		free(*line);
		*line = get_next_line(fd);
		if (!*line)
		{
			if (errno != 0)
				return (1);
			return (0);
		}
		game->file.raw_map[i] = ft_strdup(*line);
		if (!game->file.raw_map[i])
			return (free(*line), 1);
		i++;
	}
	return (0);
}

int	load_line(char *line, t_game *game)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (allocate_no(line, game));
	else if (!ft_strncmp(line, "SO ", 3))
		return (allocate_so(line, game));
	else if (!ft_strncmp(line, "EA ", 3))
		return (allocate_ea(line, game));
	else if (!ft_strncmp(line, "WE ", 3))
		return (allocate_we(line, game));
	else if (!ft_strncmp(line, "F ", 2))
		return (set_floor(line, game));
	else if (!ft_strncmp(line, "C ", 2))
		return (set_ceiling(line, game));
	return (0);
}
