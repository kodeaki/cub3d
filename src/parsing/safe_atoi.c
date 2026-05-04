/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 21:05:45 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/02 19:16:08 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	safe_atoi(const char *str, int *err)
{
	long	total;

	*err = 0;
	total = 0;
	while (*str != '\0' && ft_isdigit(*str))
	{
		total = total * 10 + (*str - '0');
		if (total < 0)
		{
			*err = 1;
			return (0);
		}
		if (total < 0 || total > 255)
		{
			*err = 1;
			return (0);
		}
		str++;
	}
	return ((int)total);
}
