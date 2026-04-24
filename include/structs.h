/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtarvain <jtarvain@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:56:02 by jtarvain          #+#    #+#             */
/*   Updated: 2026/04/23 22:54:31 by jtarvain         ###   ########.fr       */
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
	char	*c;
	char	*f;
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
	int		height;
	int		width;
};

struct s_player
{
	float		x;
	float		y;
	float		angle;
	float		fov;
	float		turn_speed;
	int			move_speed;

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
	char		**file;
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

	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	t_map		map;
	t_player	player;
	t_config	config;
	t_file		file;
};

#endif
