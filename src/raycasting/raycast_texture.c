/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:51:44 by tpirinen          #+#    #+#             */
/*   Updated: 2026/04/01 15:37:07 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	texture_to_color(t_texture *texture, int texture_x, int texture_y)
{
	int	index;
	int	color;

	if (!texture->data)
		return (0);
	if (texture_x < 0 || texture_x >= BLOCK_SIZE
		|| texture_y < 0 || texture_y >= BLOCK_SIZE)
		return (0);
	index = (texture_y * texture->size_line) + (texture_x * (texture->bpp / 8));
	color = *(unsigned int *)(texture->data + index);
	return (color);
}

static int get_texture_x(t_game *game, int orientation)
{
	int	texture_x;

	if (game->ray.hit == VERTICAL)
		texture_x = (int)game->ray.y % BLOCK_SIZE;
	if (game->ray.hit == HORIZONTAL)
		texture_x = (int)game->ray.x % BLOCK_SIZE;
	if (orientation == NO || orientation == EA)
		texture_x = BLOCK_SIZE - texture_x - 1;
	return (texture_x);
}

static int get_texture_y(int current_y, int wall_top, float height)
{
	int	texture_y;

	texture_y = (int)((float)(current_y - wall_top)
			/ height * BLOCK_SIZE);
	if (texture_y < 0)
		texture_y = 0;
	if (texture_y >= BLOCK_SIZE)
		texture_y = BLOCK_SIZE - 1;
	return (texture_y);
}

static t_texture	*select_texture(t_game *game, int orientation)
{
	if (orientation == NO)
		return (&game->config.north);
	if (orientation == SO)
		return (&game->config.south);
	if (orientation == EA)
		return (&game->config.east);
	if (orientation == WE)
		return (&game->config.west);
	return (NULL);
}

static int	get_orientation(t_game *game)
{
	if (game->ray.hit == VERTICAL)
	{
		if (game->ray.cos_angle > 0)
			return (EA);
		else
			return (WE);
	}
	else
	{
		if (game->ray.sin_angle > 0)
			return (SO);
		else
			return (NO);
	}
}

static int	get_texture_color(t_game *game, int current_y,
				int wall_top, float height)
{
	int		orientation;
	t_texture	*texture;
	int		texture_x;
	int		texture_y;
	int		color;

	orientation = get_orientation(game);
	texture = select_texture(game, orientation);
	if (texture == NULL || texture->data == NULL)
		return (0);
	texture_x = get_texture_x(game, orientation);
	texture_y = get_texture_y(current_y, wall_top, height);
	color = texture_to_color(texture, texture_x, texture_y);
	return (color);
}

static float	calculate_ray_distance(t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	distance;
	float	angle_diff;
	float	corrected;

	delta_x = game->ray.x - game->player.x;
	delta_y = game->ray.y - game->player.y;
	distance = sqrtf(delta_x * delta_x + delta_y * delta_y);
	if (distance < 0.0001f)
		distance = 0.0001f;
	angle_diff = fabsf(game->ray.angle - game->player.angle);
	corrected = distance * cosf(angle_diff);
	return (corrected);
}

static void	draw_line(t_game *game, int i)
{
	float	height;
	int		start_y;
	int		end_y;
	int		wall_top;

	game->ray.dist = calculate_ray_distance(game);
	height = (BLOCK_SIZE / game->ray.dist) * (game->window_width / 2);
	start_y = (game->window_height - height) / 2;
	end_y = start_y + height;
	wall_top = start_y;
	while (start_y < end_y)
	{
		put_pixel(game, get_texture_color(game, start_y, wall_top, height),
			i, start_y);
		start_y++;
	}
}

static void	cast_ray(t_game *game)
{
	float	previous_x;

	game->ray.x = game->player.x;
	game->ray.y = game->player.y;
	while(!touch(game, game->ray.x, game->ray.y))
	{
		game->ray.x += game->ray.cos_angle;
		game->ray.y += game->ray.sin_angle;
	}
	previous_x = game->ray.x - game->ray.cos_angle;
	if ((int)previous_x / BLOCK_SIZE != (int)game->ray.x / BLOCK_SIZE)
		game->ray.hit = VERTICAL;
	else
		game->ray.hit = HORIZONTAL;
}

static void	draw_ray(t_game *game, float ray_angle, int i)
{
	game->ray.angle = ray_angle;
	game->ray.cos_angle = cosf(ray_angle);
	game->ray.sin_angle = sinf(ray_angle);
	cast_ray(game);
	draw_line(game, i);
}

/* draws a 3D raycast with textures */
void	raycast_texture(t_game *game)
{
	int				i;
	float			half_fov;
	float			camera_x;
	float			ray_angle;

	half_fov = game->player.fov * 0.5f;
	i = 0;
	while (i < game->window_width)
	{
		if (game->window_width > 1)
			camera_x = (2.0f * (float)i / (game->window_width - 1)) - 1.0f;
		else
			camera_x = 0.0f;
		ray_angle = game->player.angle + atanf(camera_x * tanf(half_fov));
		draw_ray(game, ray_angle, i);
		i++;
	}
}
