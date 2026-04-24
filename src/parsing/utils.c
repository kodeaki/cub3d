/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:24:28 by jtarvain          #+#    #+#             */
/*   Updated: 2026/04/23 20:44:10 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(int	err, const char *msg)
{
	printf("Error.\n");
	printf("%s\n", msg);
	exit(err);
}

int		ft_close(int fd, int ret)
{
	close(fd);
	return (ret);
}

