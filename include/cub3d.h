/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:05:54 by tpirinen          #+#    #+#             */
/*   Updated: 2026/05/09 18:19:25 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BLOCK_SIZE 64
# define VERTICAL 0
# define HORIZONTAL 1

# define W      119
# define A      97
# define S      115
# define D      100
# define LEFT   65361
# define RIGHT  65363
# define ESC    65307

# define PI 3.14159265359

enum e_orientation
{
	NO,
	SO,
	EA,
	WE,
};

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
int		parse_map(t_game *game);
int		find_width(t_game *game);
void	print_parser(t_game *game);
int		scan_map(t_game *game);
int		row_width(t_game *game, const char *row, const int y);
int		copy_map(t_game *game);
void	free_mapc(void **map, int i);
int		copy_row(t_game *game, int row);
void	print_map(char **map);
int		flood_fill(t_game *game);
void	fill(t_game *game, int **visited, int y, int x);
int		compare(t_game *game, char **map, int **visited);
int		allocate_visited(t_game *game);
int		free_mlx(t_game *game);

// Initialization
void	game_init(t_game *game);

// Parsing / Map
void	create_map(t_game *game);

// Key presses
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);

// Drawing / Image output
void	put_pixel(t_game *game, int color, int x, int y);
void	draw_square(t_game *game, int size, int color, int x, int y);
void	draw_minimap(t_game *game);
void	draw_player(t_game *game, int size, int color, int x, int y);
void	draw_rays(t_player *player, t_game *game);
void	draw_map(t_game *game);
void	clear_image(t_game *game);
int		game_loop(t_game *game);
	
// Raycasting
float	distance(float x, float y);
float	fixed_dist(t_ray *ray, float player_angle);
// void	raycast(t_game *game, t_player *player);
void	raycast_texture(t_game *game);
bool	touch(t_game *game, float px, float py);

// Player
bool	player_collision(t_game *game, float x, float y);
void	move_player(t_player *player, t_game *game);

#endif
