
#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	
	(void)argv;
	if (argc != 2)
	{
		printf("Error:\nUse ./cub3d /path/to/map.cub\n");
		return (-1);
	}
	// Parsing
	
	// Initiate stuff
	game.mlx_ptr = mlx_init();
	game.window_ptr = mlx_new_window(game.mlx_ptr, 1280, 720, "cub3d");
	game.img_ptr = mlx_new_image(game.mlx_ptr, 1280, 720);
	
	// mlx_hooks
	
	mlx_loop(game.mlx_ptr);
	
	return (0);
}
