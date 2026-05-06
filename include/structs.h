/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:56:02 by jtarvain          #+#    #+#             */
/*   Updated: 2026/05/05 15:51:58 by jtarvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "typedef.h"
# include <stdbool.h>

struct s_parser
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	size_t	r_len;
	size_t	g_len;
	size_t	b_len;
	int		player_x;
	int		player_y;
	int		player_count;
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

struct s_rgb
{
	int		r;
	int		g;
	int		b;
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

struct s_point
{
	float	x;
	float	y;
};

struct s_ray
{
	t_point	origin;
	t_point	hit;
	t_point iter;
	float	angle;
};

struct s_player
{
	float		x;
	float		y;
	float		angle;
	float		fov;
	float		turn_speed;
	float		move_speed;

	float		cos_angle;
	float		sin_angle;
	float		move_x;
	float		move_y;
	
	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;
	bool		left_rotate;
	bool		right_rotate;

};

struct s_file
{
	t_parser	parser;
	t_check		check;
	int			map_start;
	int			line_count;
	char		**raw_map;
};

struct s_config
{
	void	*no_texture;
	void	*so_texture;
	void	*ea_texture;
	void	*we_texture;
	t_rgb	f;
	t_rgb	c;
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
};

#endif
