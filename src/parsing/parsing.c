/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:14:39 by jtarvain          #+#    #+#             */
/*   Updated: 2026/04/24 09:14:49 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(int argc, char **argv, t_game *game)
{
	int	fd;
	int	line_count;

	if (argc != 2 || !argv[1][0])
		return (1);
	if (check_extension(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY, 0);
	if (fd < 0)
		return (ft_close(fd, 1));
	line_count = parse_file(fd, game);
	if (!line_count)
		return (ft_close(fd, 1));
	fd = open(argv[1], O_RDONLY, 0);
	if (fd < 0)
		return (1);
	return (0);
}

