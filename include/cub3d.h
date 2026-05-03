/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:05:54 by tpirinen          #+#    #+#             */
/*   Updated: 2026/05/03 22:56:22 by jtarvain         ###   ########.fr       */
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
# include <errno.h>

// Parsing
int		parsing(int argc, char **argv, t_game *game);
int		open_file(int argc, char **argv, t_game *game);
int		copy_file(char **argv, t_game *game);
int		check_extension(char *file);
int		parse_file(int fd, t_game *game);
int		process_line(t_game *game, char *line, int i);
int		ft_strset(const char *str, const char *set);
int		ft_close(int fd, int ret);
int		add_check(t_game *game, char *line);
int		ft_check(t_game *game);
int		empty_row(char *line);
int		get_elements(int fd, t_game *game);
int		loading(int fd, volatile int *i, char **line, t_game *game);
int		load_line(char *line, t_game *game);
int		loading_map(int fd, char **line, t_game *game);
int		set_height(t_game *game);
void	ft_free(t_game *game);
void	ft_exit(int err, const char *msg);
int		allocate_no(char *line, t_game *game);
int		allocate_so(char *line, t_game *game);
int		allocate_ea(char *line, t_game *game);
int		allocate_we(char *line, t_game *game);
int		set_floor(char *line, t_game *game);
int		set_ceiling(char *line, t_game *game);
size_t	check_line(char *line, int mod);
int		ft_space(char c);
void	free_map(char **map);
int		set_color(char *line, int *color, size_t len);
int		safe_atoi(const char *str, int *err);


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
void	draw_rays(t_player *player, t_game *game);
void	draw_map(t_game *game);
void	clear_image(t_game *game);
int		game_loop(t_game *game);

// Raycasting
float	distance(float x, float y);
float	fixed_dist(t_ray *ray, float player_angle);
void	raycast(t_game *game, t_player *player);
bool	touch(float px, float py, t_game *game);

// Player
bool	player_collision(t_game *game, float x, float y);
void	move_player(t_player *player, t_game *game);

#endif
