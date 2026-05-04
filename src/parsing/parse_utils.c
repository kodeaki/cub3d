/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:44:19 by jtarvain          #+#    #+#             */
/*   Updated: 2026/04/24 13:28:23 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check(t_game *game)
{
	t_check	checker;

	checker = game->file.check;
	if (checker.c != 1 || checker.f != 1 || checker.no != 1 ||
			checker.so != 1 || checker.we != 1 || checker.ea != 1)
		return (1);
	if (!game->file.map_start)
		return (1);
	return (0);
}

int	empty_row(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == ' ' || line[i] == '\t' || line[i] == '\v' ||
				line[i] == '\n'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_strset(const char *str, const char *set)
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
