/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:44:19 by jtarvain          #+#    #+#             */
/*   Updated: 2026/04/24 09:14:49 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		add_check(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		game->file->check->no++;
	else if (!ft_strncmp(line, "SO ", 3))
		game->file->check->so++;
	else if (!ft_strncmp(line, "EA ", 3))
		game->file->check->ea++;
	else if (!ft_strncmp(line, "WE ", 3))
		game->file->check->we++;
	else if (!ft_strncmp(line, "C ", 2))
		game->file->check->c++;
	else if (!ft_strncmp(line, "F ", 2))
		game->file->check->f++;
	return (0);
}

int		ft_strset(const char *str, const char *set)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i] && str[i] != '\n')
	{
		j = 0;
		ret = 1;
		while (set[j])
		{
			if (str[i] == set[j])
				ret = 0;
			j++;
		}
		if (ret)
			return (ret);
		i++;
	}
	return (ret);
}
