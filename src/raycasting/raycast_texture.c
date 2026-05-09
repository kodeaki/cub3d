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
	int	bytes_per_pixel;
	int	index;
	char	*pixel;
	int	color;

	if (texture_x < 0)
		texture_x = 0;
	if (texture_y < 0)
		texture_y = 0;
	if (texture_x >= BLOCK_SIZE)
		texture_x = BLOCK_SIZE - 1;
	if (texture_y >= BLOCK_SIZE)
		texture_y = BLOCK_SIZE - 1;
	bytes_per_pixel = texture->bpp / 8;
	index = texture_y * texture->size_line;
	index = index + texture_x * bytes_per_pixel;
	pixel = texture->data + index;
	color = (unsigned char)pixel[0];
	color = color | ((unsigned char)pixel[1] << 8);
	color = color | ((unsigned char)pixel[2] << 16);
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

static int get_texture_y(t_game *game, int start_y, float height)
{
	int	texture_y;

	texture_y = (int)((float)(start_y - game->window_height / 2)
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

static int	get_texture_color(t_game *game, int start_y, float height)
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
	texture_y = get_texture_y(game, start_y, height);
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
	angle_diff = game->ray.angle - game->player.angle;
	corrected = distance * cosf(angle_diff);
	if (corrected < 0.0001f)
		corrected = 0.0001f;
	return (corrected);
}

static void	draw_line(t_game *game, int i)
{
	float	height;
	int		start_y;
	int		end_y;

	game->ray.dist = calculate_ray_distance(game);
	height = (BLOCK_SIZE / game->ray.dist) * (game->window_width / 2);
	start_y = (game->window_height - height) / 2;
	end_y = start_y + height;
	while (start_y < end_y)
	{
		put_pixel(game, get_texture_color(game, start_y, height), i, start_y);
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
	game->ray.cos_angle = cos(ray_angle);
	game->ray.sin_angle = sin(ray_angle);
	cast_ray(game);
	draw_line(game, i);
}

/* draws a 3D raycast with textures */
void	raycast_texture(t_game *game)
{
	int				i;
	float			angle_step;

	game->ray.angle = game->player.angle - (game->player.fov / 2.0f);
	if (game->window_width > 1)
		angle_step = game->player.fov / (float)(game->window_width - 1);
	else
		angle_step = 0.0f;
	i = 0;
	while (i < game->window_width)
	{
		draw_ray(game, game->ray.angle, i);
		game->ray.angle += angle_step;
		i++;
	}
}
