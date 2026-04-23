/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:14:39 by jtarvain          #+#    #+#             */
/*   Updated: 2026/04/21 14:04:14 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(int argc, char **argv, t_game *game)
{
	int	fd;

	if (argc != 2 || !argv[1][0])
		return (1);
	if (check_extension(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY, 0);
	if (fd < 0)
		return (ft_close(fd, 1));
	if (load_map(fd, game))
		return (ft_close(fd, 1));
	return (0);
}

int	load_map(int fd, t_game *game)
{
	int		i;
	char	*line;
	
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{
		process_line(game, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
	return (ft_close(fd, 0));
}

int	process_line(t_game *game, char *line)
{
	// split h files
	static int	flag;
	(void)flag;
	(void)game;
	(void)line;
	return (0);
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
