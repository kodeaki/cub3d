#include "cub3d.h"

void	ray_project_wall(t_game *game)
{
	// Compute perpendicular distance using side and side distances.
	// Convert distance to line_height for wall slice height.
	// Compute draw_start and draw_end centered on screen.
	// Clamp draw_start and draw_end to the screen bounds.
}

void	ray_project_texture(t_game *game)
{
	// Compute wall_x as fractional hit position along the wall.
	// Convert wall_x to texture_x, flipping based on side and ray_dir.
	// Compute texture_step from texture height and line_height.
	// Compute texture_pos start for the first pixel in the stripe.
}
