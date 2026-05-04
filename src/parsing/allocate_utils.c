/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 01:39:49 by jtarvain          #+#    #+#             */
/*   Updated: 2026/04/29 15:17:35 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	check_line(char *line)
{
	size_t	i;
	size_t	k;

	i = 3;
	if (!line[i] || ft_space(line[i]))
		return (0);
	while (line[i] && !ft_space(line[i]))
		i++;
	k = i;
	while (line[k] && ft_space(line[k]))
		k++;
	if (line[k] && !ft_space(line[k]))
		return (0);
	return (i);
}

int	ft_space(char c)
{
	if (c == '\v' || c == '\t' || c == ' ' || c == '\n')
		return (1);
	return (0);
}
