#include "cub3d.h"

void	ray_camera_setup(t_game *game)
{
	// Compute sin and cos from the player angle once per frame.
	
	// Build dir_x and dir_y from cos and sin.
	// Build plane_x and plane_y perpendicular to dir, scaled by FOV.
	// Set camera_step to 2.0 / window_width for camera space stepping.
	// Initialize camera_x to -1.0 for the leftmost column.
}

void	ray_camera_advance(t_game *game)
{
	// Advance camera_x by camera_step for the next screen column.
}
