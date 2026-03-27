
#include "cub3d.h"

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
	game_init(&game);

	// mlx_hooks
	
	mlx_loop(game.mlx_ptr);
	
	return (0);
}
