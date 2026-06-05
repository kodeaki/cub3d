/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:14:39 by jtarvain          #+#    #+#             */
/*   Updated: 2026/06/05 20:26:50 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(int argc, char **argv, t_game *game)
{
	if (open_file(argc, argv, game))
		return (1);
	if (set_height(game))
		return (1);
	if (copy_file(argv, game))
		return (1);
	if (parse_map(game))
		return (1);
	return (0);
}
