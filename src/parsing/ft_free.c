/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:22:54 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/09 18:20:43 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(t_game *game)
{
	if (game->config.north.path)
		free(game->config.north.path);
	if (game->config.south.path)
		free(game->config.south.path);
	if (game->config.east.path)
		free(game->config.east.path);
	if (game->config.west.path)
		free(game->config.west.path);
	if (game->file.raw_map)
		free_map(game->file.raw_map);
	if (game->map.arr)
		free_map(game->map.arr);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_mapc(void **map, int i)
{
	while (i > 0)
		free(map[--i]);
	free(map);
}

int	free_mlx(t_game *game)
{
	ft_free(game);
	if (game->image)
		mlx_destroy_image(game->mlx, game->image);
	if (game->config.north.img)
		mlx_destroy_image(game->mlx, game->config.north.img);
	if (game->config.south.img)
		mlx_destroy_image(game->mlx, game->config.south.img);
	if (game->config.east.img)
		mlx_destroy_image(game->mlx, game->config.east.img);
	if (game->config.west.img)
		mlx_destroy_image(game->mlx, game->config.west.img);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
	return (0);
}
