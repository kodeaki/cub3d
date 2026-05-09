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

static int	texture_color_at(t_texture *texture, int texture_x, int texture_y)
{
	int	index;

	if (!texture->data)
		return (0);
	if (texture_x < 0 || texture_x >= BLOCK_SIZE
		|| texture_y < 0 || texture_y >= BLOCK_SIZE)
		return (0);
	index = (texture_y * texture->size_line)
		+ (texture_x * (texture->bpp / 8));
	return (*(unsigned int *)(texture->data + index));
}

static t_texture	*get_wall_texture(t_game *game, int *texture_x)
{
	int	orientation;

	if (game->ray.hit == VERTICAL)
		orientation = (game->ray.cos_angle > 0) ? EA : WE;
	else
		orientation = (game->ray.sin_angle > 0) ? SO : NO;
	*texture_x = get_texture_x(game, orientation);
	if (*texture_x < 0)
		*texture_x = 0;
	if (*texture_x >= BLOCK_SIZE)
		*texture_x = BLOCK_SIZE - 1;
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

static void	draw_wall_pixels_fast(t_game *game, t_texture *texture,
						int texture_x, int x,
						int start_y, int end_y,
						float tex_step, float tex_pos)
{
	int	y;
	int	tex_y;
	int	*row;

	y = start_y;
	while (y < end_y)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= BLOCK_SIZE)
			tex_y = BLOCK_SIZE - 1;
		row = (int *)(game->data + (y * game->size_line));
		row[x] = texture_color_at(texture, texture_x, tex_y);
		tex_pos += tex_step;
		y++;
	}
}

static void	draw_wall_pixels_slow(t_game *game, t_texture *texture,
						int texture_x, int x,
						int start_y, int end_y,
						float tex_step, float tex_pos)
{
	int	y;
	int	tex_y;

	y = start_y;
	while (y < end_y)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= BLOCK_SIZE)
			tex_y = BLOCK_SIZE - 1;
		put_pixel(game, texture_color_at(texture, texture_x, tex_y), x, y);
		tex_pos += tex_step;
		y++;
	}
}

static void	draw_wall_pixels(t_game *game, t_texture *texture, int texture_x,
						int x, int start_y, int end_y,
						float tex_step, float tex_pos)
{
	if (game->bits_per_pixel == 32)
		draw_wall_pixels_fast(game, texture, texture_x, x,
			start_y, end_y, tex_step, tex_pos);
	else
		draw_wall_pixels_slow(game, texture, texture_x, x,
			start_y, end_y, tex_step, tex_pos);
}

static void	clamp_draw_range(int *start_y, int *end_y, int height)
{
	if (*start_y < 0)
		*start_y = 0;
	if (*end_y > height)
		*end_y = height;
}

static void	draw_wall_column(t_game *game, int x,
						int start_y, int end_y,
						int wall_top, float height)
{
	int		texture_x;
	float	tex_step;
	float	tex_pos;
	t_texture	*texture;

	texture = get_wall_texture(game, &texture_x);
	if (!texture || !texture->data || height <= 0.0f)
		return ;
	tex_step = (float)BLOCK_SIZE / height;
	tex_pos = (start_y - wall_top) * tex_step;
	draw_wall_pixels(game, texture, texture_x, x,
		start_y, end_y, tex_step, tex_pos);
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
	wall_top = (game->window_height - height) / 2;
	start_y = wall_top;
	end_y = wall_top + height;
	clamp_draw_range(&start_y, &end_y, game->window_height);
	draw_wall_column(game, i, start_y, end_y, wall_top, height);
}

static void	cast_ray(t_game *game)
{
	float	previous_x;

	game->ray.x = game->player.x;
	game->ray.y = game->player.y;
	while (!touch(game, game->ray.x, game->ray.y))
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
	int		i;
	float	half_fov;
	float	camera_x;
	float	ray_angle;

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
