/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:27:36 by tpirinen          #+#    #+#             */
/*   Updated: 2026/05/20 15:54:10 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	// Build camera basis for the frame (dir, plane, step, camera_x start).
	// Set the column index to the left edge of the screen.

	// While the column index is within the screen width:
	//   Initialize ray and DDA state for this column.
	//   Run DDA stepping until a wall or boundary is hit.
	//   Project the hit distance into wall height on screen.
	//   Compute texture coordinates for this column if textured.
	//   Draw the vertical stripe into the image buffer.
	//   Advance camera_x and the column index for the next ray.
}
