#include "cub3d.h"

// AI made function to test the dda implementation so far. remove later
void	test_dda(t_game *game)
{
	double	perp_dist;
	int		draw_start;
	int		draw_end;
	int		y;
	int		color;

	/* compute perpendicular distance */
	if (game->ray.side == false)
	{
		if (game->ray.dir.x == 0.0)
			perp_dist = 1e30;
		else
			perp_dist = (game->ray.map_x - game->player.pos.x
				+ (1 - game->ray.step_x) / 2.0) / game->ray.dir.x;
	}
	else
	{
		if (game->ray.dir.y == 0.0)
			perp_dist = 1e30;
		else
			perp_dist = (game->ray.map_y - game->player.pos.y
				+ (1 - game->ray.step_y) / 2.0) / game->ray.dir.y;
	}
	if (perp_dist <= 0.0)
		perp_dist = 1e-6;
	game->ray.perp_dist = perp_dist;

	/* line height and draw bounds */
	game->ray.line_height = (int)((double)game->window_height / perp_dist);
	draw_start = -game->ray.line_height / 2 + (int)game->window_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	game->ray.draw_start = draw_start;
	draw_end = game->ray.line_height / 2 + (int)game->window_height / 2;
	if (draw_end >= (int)game->window_height)
		draw_end = (int)game->window_height - 1;
	game->ray.draw_end = draw_end;

	/* simple color and shading for testing */
	color = 0xCCCCCC;
	if (game->ray.side)
		color = (color >> 1) & 0x7F7F7F;

	y = draw_start;
	while (y <= draw_end)
	{
		put_pixel(game, color, game->ray.screen_x, y);
		++y;
	}
}
