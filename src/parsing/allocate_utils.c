/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 01:39:49 by jtarvain          #+#    #+#             */
/*   Updated: 2026/06/26 13:38:27 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	no_trailing_content(char *str)
{
	while (*str)
	{
		if (!ft_space(*str))
			return (1);
		str++;
	}
	return (0);
}

size_t	check_line(char *line, int mod)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!mod)
		i = 3;
	else
		i = 2;
	while (line[i] && ft_space(line[i]) && line[i] != '\n')
		i++;
	j = i;
	if (!line[i] || line[i] == '\n')
		return (0);
	while (line[i] && !ft_space(line[i]))
		i++;
	k = i;
	while (line[k] && ft_space(line[k]))
		k++;
	if (line[k] && !ft_space(line[k]))
		return (0);
	return (i - j);
}

int	ft_space(char c)
{
	if (c == '\v' || c == '\t' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

int	set_color(char *line, int *color, size_t len)
{
	char	*str;
	size_t	i;
	int		err;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (1);
	i = 0;
	while (i < len && line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	*color = safe_atoi(str, &err);
	if (err)
		return (free(str), 1);
	return (free(str), 0);
}
