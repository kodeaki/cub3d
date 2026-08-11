/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delta_seconds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:54:20 by tpirinen          #+#    #+#             */
/*   Updated: 2026/06/28 10:56:13 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_delta_seconds(void)
{
	static struct timeval	last = {0, 0};
	struct timeval			now;
	double					dt;

	if (gettimeofday(&now, NULL) != 0)
		return (0.016);
	if (last.tv_sec == 0 && last.tv_usec == 0)
		dt = 0.016;
	else
		dt = (now.tv_sec - last.tv_sec) + (now.tv_usec - last.tv_usec) / 1e6;
	if (dt < 0.0)
		dt = 0.0;
	if (dt > 0.1)
		dt = 0.1;
	last = now;
	return (dt);
}
