/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:54:20 by tpirinen          #+#    #+#             */
/*   Updated: 2026/03/31 17:04:25 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_player *player)
{
	float	cos_angle;
	float	sin_angle;
	float	move_x;
	float	move_y;
	float	move_len;

	if (player->left_rotate)
		player->angle -= player->turn_speed;
	if (player->right_rotate)
		player->angle += player->turn_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	move_x = 0.0f;
	move_y = 0.0f;
	if (player->key_up)
	{
		move_x += cos_angle;
		move_y += sin_angle;
	}
	if (player->key_down)
	{
		move_x -= cos_angle;
		move_y -= sin_angle;
	}
	if (player->key_left)
	{
		move_x += sin_angle;
		move_y -= cos_angle;
	}
	if (player->key_right)
	{
		move_x -= sin_angle;
		move_y += cos_angle;
	}
	move_len = sqrtf(move_x * move_x + move_y * move_y);
	if (move_len > 0.0f)
	{
		move_x /= move_len;
		move_y /= move_len;
		player->x += move_x * player->move_speed;
		player->y += move_y * player->move_speed;
	}
}
