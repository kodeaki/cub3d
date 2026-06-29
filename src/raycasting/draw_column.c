/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:27:36 by tpirinen          #+#    #+#             */
/*   Updated: 2026/06/28 10:55:42 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_draw_clamp(t_game *game, double *texture_v)
{
	int	unclamped_start;

	unclamped_start = -game->ray.line_height * 0.5 + game->window_height * 0.5;
	if (unclamped_start < 0)
	{
		*texture_v = (-unclamped_start) * game->ray.texture_step;
		game->ray.draw_start = 0;
	}
	else
	{
		*texture_v = 0.0;
		game->ray.draw_start = unclamped_start;
	}
	game->ray.draw_end = game->ray.line_height * 0.5
		+ game->window_height * 0.5;
	if (game->ray.draw_end >= game->window_height)
		game->ray.draw_end = game->window_height - 1;
}

static uint32_t	get_texture_pixel(t_texture *texture, int x, int y)
{
	uint32_t	*data;
	uint32_t	color;

	data = (uint32_t *)texture->data;
	color = data[y * texture->width + x];
	return (color);
}

/* 
 * 't_texture' is the current N, S, E, W texture being drawn
 * 'texture_v' gets incremented by 'texture_step' to keep the
 * proportions of the texture correct. Passing 'texture_v' to
 * get_texture_pixel() as an integer gets the correct index of
 * the pixel from the texture. ie. 'texture_v' = 3.23, 
 * (int)texture_v = 3, so the 4th pixel from the top is retrieved.
 */
void	draw_column(t_game *game, uint32_t *data, int col)
{
	t_texture	*texture;
	int			draw_y;
	double		texture_v;
	uint32_t	color;

	texture = get_wall_texture(game);
	calculate_draw_clamp(game, &texture_v);
	draw_y = game->ray.draw_start;
	while (draw_y < game->ray.draw_end)
	{
		color = get_texture_pixel(texture, game->ray.texture_x, (int)texture_v);
		data[(int)(draw_y * game->window_width + col)] = color;
		texture_v += game->ray.texture_step;
		draw_y++;
	}
}
