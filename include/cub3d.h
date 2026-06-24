/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:05:54 by tpirinen          #+#    #+#             */
/*   Updated: 2026/06/03 14:19:03 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Change players field of view. 1° < FOV_DEG < 180°
# define FOV_DEG 90

// Change players move speed and turn speed
//  1 - - - - 3 - - - - 5 - - - - - - 10 - - - - - - - 50
// slow - - fast - - super fast - ultra fast - - uncontrollable
# define MOVE_SPEED 3
# define TURN_SPEED 3

# define W      119
# define A      97
# define S      115
# define D      100
# define LEFT   65361
# define RIGHT  65363
# define ESC    65307

# include "minilibx-linux/mlx.h"
# include "libft.h"
# include "structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/time.h>

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
bool	touch(t_game *game, double px, double py);
void	put_pixel(t_game *game, int color, int x, int y);
void	draw_minimap(t_game *game);
void	draw_player(t_game *game, int size, int color);
void	draw_rays(t_player *player, t_game *game);
void	draw_map(t_game *game);
void	clear_image(t_game *game);
int		game_loop(t_game *game);
	
// Raycasting
void		raycast(t_game *game);
void		ray_init(t_game *game, int col);
void		ray_dda(t_game *game);
void		texture_setup(t_game *game);
t_texture	*get_wall_texture(t_game *game);
void		draw_column(t_game *game);

// Player
bool	player_collision(t_game *game, double x, double y);
double	get_delta_seconds(void);
void	move_player(t_player *player, t_game *game);

#endif
