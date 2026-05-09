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

bool	player_collision(t_game *game, float x, float y)
{
	return (touch(game, x, y));
}

static void	rotate_player(t_player *player)
{
	if (player->left_rotate)
		player->angle -= player->turn_speed;
	if (player->right_rotate)
		player->angle += player->turn_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
}

static void	calculate_movement(t_player *player)
{
	if (player->key_up)
	{
		player->move_x += player->cos_angle;
		player->move_y += player->sin_angle;
	}
	if (player->key_down)
	{
		player->move_x -= player->cos_angle;
		player->move_y -= player->sin_angle;
	}
	if (player->key_left)
	{
		player->move_x += player->sin_angle;
		player->move_y -= player->cos_angle;
	}
	if (player->key_right)
	{
		player->move_x -= player->sin_angle;
		player->move_y += player->cos_angle;
	}
}

static void	apply_movement(t_player *player, t_game *game)
{
	float	move_len;
	float	new_x;
	float	new_y;

	move_len = sqrtf(player->move_x * player->move_x
			+ player->move_y * player->move_y);
	if (move_len <= 0.0f)
		return ;
	player->move_x /= move_len;
	player->move_y /= move_len;
	new_x = player->x + player->move_x * player->move_speed;
	new_y = player->y + player->move_y * player->move_speed;
	if (!player_collision(game, new_x, player->y))
		player->x = new_x;
	if (!player_collision(game, player->x, new_y))
		player->y = new_y;
}

void	move_player(t_player *player, t_game *game)
{
	player->move_x = 0.0f;
	player->move_y = 0.0f;
	rotate_player(player);
	calculate_movement(player);
	apply_movement(player, game);
}
