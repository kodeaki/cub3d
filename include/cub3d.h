/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:05:54 by tpirinen          #+#    #+#             */
/*   Updated: 2026/04/23 17:35:07 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1185
# define HEIGHT 720

# define BLOCK_SIZE 64

# define W      119
# define A      97
# define S      115
# define D      100
# define LEFT   65361
# define RIGHT  65363
# define ESC    65307

# define PI 3.14159265359

# include "minilibx-linux/mlx.h"
# include "libft.h"
# include "structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>


// Parsing
int		parsing(int argc, char **argv, t_game *game);
int		check_extension(char *file);
int		parse_file(int fd, t_game *game);
int		process_line(t_game *game, char *line, int i);
void	ft_exit(int err, const char *msg);
int		ft_close(int fd, int ret);
int		add_check(t_game *game, char *line);

// Initialization
void	game_init(t_game *game);
void	player_init(t_player *player);

// Parsing / Map
void	create_map(t_game *game);

// Key presses
int		key_press(int keycode, t_player *player);
int		key_release(int keycode, t_player *player);

// Drawing / Image output
void	put_pixel(int x, int y, int color, t_game *game);
void	draw_square(int x, int y, int size, int color, t_game *game);
void	draw_minimap(t_game *game);
void	draw_player(int x, int y, int size, int color, t_game *game);
void	draw_line(t_player *player, t_game *game, float start_x, int i);
void	draw_line_map(t_player *player, t_game *game, float start_x);
void	draw_map(t_game *game);
void	clear_image(t_game *game);
int		draw_loop(t_game *game);

// Raycasting
bool	touch(float px, float py, t_game *game);

// Player
void	move_player(t_player *player);

#endif
