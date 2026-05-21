#include "cub3d.h"

void	ray_dda_init(t_game *game)
{
	// Build ray_dir from camera dir plus plane scaled by camera_x.
	// Set map_x and map_y from the player position.
	// Compute delta distances from ray_dir components.
	// Choose step_x and step_y based on ray_dir sign.
	// Compute initial side distances to the first grid boundaries.
	// Reset hit flag and side indicator.
}

void	ray_dda_run(t_game *game)
{
	// While no wall hit:
	//   Compare sidedist_x and sidedist_y.
	//   Step in x or y direction and update sidedist.
	//   Update map_x/map_y and set side accordingly.
	//   Check map bounds; stop if ray exits the map.
	//   Check map cell for wall; set hit if wall found.
}
