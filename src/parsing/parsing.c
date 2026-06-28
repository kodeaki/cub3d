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

void	parsing(int argc, char **argv, t_game *game)
{
	open_file(argc, argv, game);
	set_height(game);
	copy_file(argv, game);
	parse_map(game);
}
