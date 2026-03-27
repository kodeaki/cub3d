
#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1280
# define HEIGHT 720

# define W      119
# define A      97
# define S      115
# define D      100
# define LEFT   65361
# define RIGHT  65363
# define ESC    65307

# include "minilibx-linux/mlx.h"

# include <stdio.h>
//# include <stdlib.h>
# include <stdbool.h>
//# include <math.h>

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	float	fov;
	float	turn_speed;
	int		move_speed;

	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;


}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*window_ptr;
	void		*img_ptr;
	
	t_player	player;
}	t_game;

void	game_init(t_game *game);
void	player_init(t_player *player);

#endif
