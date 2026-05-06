/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:27:37 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/06 16:39:27 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_imap(t_game *game);

int	allocate_visited(t_game *game)
{
	int	i;

	i = 0;
	game->map.visited = malloc(sizeof(int *) * (game->map.height + 1));
	if (!game->map.visited)
		return (1);
	game->map.visited[game->map.height] = NULL;
	while (i < game->map.height)
	{
		game->map.visited[i] = ft_calloc(game->map.width, sizeof(int));
		if (!game->map.visited[i])
			return (free_mapc(game->map.visited, i), 1);
		i++;
	}
	print_imap(game);
	printf("game height: %i\n", game->map.height);
	printf("game width: %i\n", game->map.width);
	return (0);
}

static void	print_imap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			printf("%i", game->map.visited[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
