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

bool	player_collision(t_game *game, double x, double y)
{
	return (touch(game, x, y));
}

static void	rotate_player(t_player *player)
{
	double	rotation;
	double	cos_a;
	double	sin_a;
	double	old_dir_x;
	double	old_plane_x;

	if (player->left_rotate == player->right_rotate)
		return ;
	rotation = player->turn_speed;
	if (player->left_rotate)
		rotation = -rotation;
	cos_a = cos(rotation);
	sin_a = sin(rotation);
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos_a - player->dir.y * sin_a;
	player->dir.y = old_dir_x * sin_a + player->dir.y * cos_a;
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos_a - player->plane.y * sin_a;
	player->plane.y = old_plane_x * sin_a + player->plane.y * cos_a;
}

static void	calculate_movement(t_player *player)
{
	double	perp_x;
	double	perp_y;

	perp_x = player->dir.y;
	perp_y = -player->dir.x;
	if (player->key_up)
	{
		player->move_x += player->dir.x;
		player->move_y += player->dir.y;
	}
	if (player->key_down)
	{
		player->move_x -= player->dir.x;
		player->move_y -= player->dir.y;
	}
	if (player->key_left)
	{
		player->move_x += perp_x;
		player->move_y += perp_y;
	}
	if (player->key_right)
	{
		player->move_x -= perp_x;
		player->move_y -= perp_y;
	}
}

static void	apply_movement(t_player *player, t_game *game)
{
	double	move_len;
	double	new_x;
	double	new_y;

	move_len = sqrt(player->move_x * player->move_x
			+ player->move_y * player->move_y);
	if (move_len <= 0)
		return ;
	player->move_x /= move_len;
	player->move_y /= move_len;
	new_x = player->pos.x + player->move_x * player->move_speed;
	new_y = player->pos.y + player->move_y * player->move_speed;
	if (!player_collision(game, new_x, player->pos.y))
		player->pos.x = new_x;
	if (!player_collision(game, player->pos.x, new_y))
		player->pos.y = new_y;
}

void	move_player(t_player *player, t_game *game)
{
	player->move_x = 0;
	player->move_y = 0;
	rotate_player(player);
	calculate_movement(player);
	apply_movement(player, game);
}
