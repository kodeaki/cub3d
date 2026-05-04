/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 09:07:49 by jtarvain          #+#    #+#             */
/*   Updated: 2026/04/24 09:14:49 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_a(int argc, char **argv, t_game *game)
{

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
			return (free(line), ft_close(fd, 0));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
	return (ft_close(fd, i));
}

int	process_line(t_game *game, char *line, int i)
{
	if (!ft_strset(line, "10NSEW ") && !game->file->map_start)
	{
		game->file->map_start = i;
		return (0);
	}
	if (!ft_strset(line, "10NSEW "))
		return (0);
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) ||
			!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3) ||
			!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
	{
		add_check(game, line);
		return (0);
	}
	if (game->file->map_start && !ft_strset(line, " \t\v"))
		return (1);
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
