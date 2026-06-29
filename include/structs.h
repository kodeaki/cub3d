/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:56:02 by jtarvain          #+#    #+#             */
/*   Updated: 2026/06/28 11:00:27 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "typedef.h"
# include <stdbool.h>
# include <stdint.h>

enum e_orientation
{
	NO,
	SO,
	EA,
	WE,
};

enum e_side
{
	X_SIDE,
	Y_SIDE
};

struct s_rgb
{
	int		r;
	int		g;
	int		b;
};

struct s_parser
{
	size_t			r_len;
	size_t			g_len;
	size_t			b_len;
	int				player_x;
	int				player_y;
	t_orientation	orientation;
	int				player_count;
	t_rgb			f;
	t_rgb			c;
	bool			out_of_bounds;
};

struct s_check
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	c;
	int	f;
};

struct s_map
{
	char	**arr;
	int		**visited;
	int		height;
	int		width;
};

struct s_minimap
{
	int	width;
	int	height;
	int	cell;
};

struct s_file
{
	t_parser	parser;
	t_check		check;
	int			map_start;
	int			line_count;
	char		**raw_map;
};

struct s_texture
{
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	void	*img;
	char	*data;
	char	*path;
};

struct s_config
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;

	uint32_t	floor;
	uint32_t	ceiling;
};

struct s_vector
{
	double	x;
	double	y;
};

struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;

	double		turn_speed;
	double		move_speed;

	double		move_x;
	double		move_y;

	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;

	bool		left_rotate;
	bool		right_rotate;
};

struct s_raycast
{
	t_vector	dir;

	int			map_x;
	int			map_y;

	double		sidedist_x;
	double		sidedist_y;

	double		deltadist_x;
	double		deltadist_y;

	int			step_x;
	int			step_y;
	bool		side;
	bool		hit;

	double		perp_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;

	double		texture_u;
	int			texture_x;
	double		texture_step;
};

struct s_game
{
	void		*mlx;
	void		*window;
	void		*image;

	float		window_width;
	float		window_height;

	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	t_map		map;
	t_minimap	minimap;
	t_player	player;
	t_config	config;
	t_file		file;
	t_raycast	ray;
};

#endif
