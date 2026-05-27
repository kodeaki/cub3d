/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:05:00 by tpirinen          #+#    #+#             */
/*   Updated: 2026/03/31 15:09:32 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	texture_init(t_game *game, t_texture *texture)
{
	int	w;
	int	h;

	texture->img = mlx_xpm_file_to_image(game->mlx, texture->path, &w, &h);
	if (texture->img == NULL)
	{
		printf("Error: Failed to load texture %s\n", texture->path);
		free_mlx(game);
		exit(1);
	}
	texture->data = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size_line, &texture->endian);
}

static void	set_player_direction(t_game *game)
{
	if (game->file.parser.orientation == NO)
	{
		game->player.dir.x = 0;
		game->player.dir.y = -1;
	}
	else if (game->file.parser.orientation == SO)
	{
		game->player.dir.x = 0;
		game->player.dir.y = 1;
	}
	else if (game->file.parser.orientation == WE)
	{
		game->player.dir.x = -1;
		game->player.dir.y = 0;
	}
	else if (game->file.parser.orientation == EA)
	{
		game->player.dir.x = 1;
		game->player.dir.y = 0;
	}
}

static void	set_player_plane(t_game *game)
{
	double	plane_len;

	plane_len = tan(game->player.fov / 2);
	game->player.plane.x = -game->player.dir.y * plane_len;
	game->player.plane.y = game->player.dir.x * plane_len;
}

static void	player_init(t_game *game)
{
	game->player.pos.x = game->file.parser.player_x * BLOCK_SIZE;
	game->player.pos.y = game->file.parser.player_y * BLOCK_SIZE;
	set_player_direction(game);
	game->player.fov_degrees = 90;
	game->player.fov = game->player.fov_degrees * (PI / 180);
	set_player_plane(game);
	game->player.move_speed = 0.5;
	game->player.turn_speed = 0.01;
	game->player.key_up = false;
	game->player.key_down = false;
	game->player.key_right = false;
	game->player.key_left = false;
	game->player.left_rotate = false;
	game->player.right_rotate = false;
}

void	game_init(t_game *game)
{
	int	screen_width;
	int	screen_height;

	game->mlx = mlx_init();
	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	game->window_width = screen_width * 0.5;
	game->window_height = screen_height * 0.4;
	player_init(game);
	game->window = mlx_new_window(game->mlx, game->window_width,
			game->window_height, "cub3d");
	game->image = mlx_new_image(game->mlx, game->window_width,
			game->window_height);
	game->data = mlx_get_data_addr(game->image, &game->bits_per_pixel,
			&game->size_line, &game->endian);
	texture_init(game, &game->config.north);
	texture_init(game, &game->config.south);
	texture_init(game, &game->config.east);
	texture_init(game, &game->config.west);
	mlx_put_image_to_window(game->mlx, game->window, game->image, 0, 0);
}
