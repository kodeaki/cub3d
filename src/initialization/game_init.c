
#include "cub3d.h"

void	game_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->window_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	game->img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
}
	