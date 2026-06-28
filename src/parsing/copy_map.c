/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:07:57 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/06 15:54:18 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_map(t_game *game)
{
	int	i;

	game->map.arr = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.arr)
		ft_exit(game, ERR_MEMORY_ALLOC);
	game->map.arr[game->map.height] = NULL;
	i = 0;
	while (i < game->map.height)
	{
		game->map.arr[i] = malloc(sizeof(char) * (game->map.width + 1));
		if (!game->map.arr[i])
		{
			free_mapc(game->map.arr, i);
			ft_exit(game, ERR_MEMORY_ALLOC);
		}
		copy_row(game, i);
		i++;
	}
}

void	copy_row(t_game *game, int row)
{
	int		len;
	int		i;

	len = row_width(game, game->file.raw_map[row], row);
	i = 0;
	while (i < len && game->file.raw_map[row][i])
	{
		game->map.arr[row][i] = game->file.raw_map[row][i];
		i++;
	}
	while (i < game->map.width)
	{
		game->map.arr[row][i] = ' ';
		i++;
	}
	game->map.arr[row][i] = '\0';
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
