/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <abkhefif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:42:23 by abkhefif          #+#    #+#             */
/*   Updated: 2025/09/13 17:38:27 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_floor_and_walls(t_game *game, t_images *imgs, int x, int y)
{
	int	screen_x;
	int	screen_y;

	screen_x = (x * imgs->size) - game->camera_x;
	screen_y = (y * imgs->size) - game->camera_y;
	mlx_put_image_to_window(game->mlx, game->window, imgs->floor,
		screen_x, screen_y);
	if (game->map->grid[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, imgs->wall,
			screen_x, screen_y);
	else if (game->map->grid[y][x] == '3')
		mlx_put_image_to_window(game->mlx, game->window, imgs->floor2,
			screen_x, screen_y);
}

static void	render_animated_objects(t_game *game, t_images *imgs, int x, int y)
{
	int	screen_x;
	int	screen_y;

	screen_x = (x * imgs->size) - game->camera_x;
	screen_y = (y * imgs->size) - game->camera_y;
	if (game->map->grid[y][x] == 'P')
	{
		void *current_sprite;
		if (game->player_direction == LEFT)
			current_sprite = imgs->player_move_right[game->frame];
		else if (game->player_direction == RIGHT)
			current_sprite = imgs->player_move_left[game->frame];
		else
			current_sprite = imgs->player_move_right[game->frame];
		mlx_put_image_to_window(game->mlx, game->window,
			current_sprite, screen_x, screen_y);
		game->frame = (game->frame + 1) % 7;
	}
	else if (game->map->grid[y][x] == 'Z')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			imgs->cat[game->cat_frame], screen_x, screen_y);
		game->cat_frame = (game->cat_frame + 1) % 2;
	}
	else if (game->map->grid[y][x] == 'K')
		mlx_put_image_to_window(game->mlx, game->window, imgs->mom,
			screen_x, screen_y);
}

static void	render_tile(t_game *game, t_images *imgs, int x, int y)
{
	int	screen_x;
	int	screen_y;

	screen_x = (x * imgs->size) - game->camera_x;
	screen_y = (y * imgs->size) - game->camera_y;
	if (screen_x >= -128 && screen_x < 1920
		&& screen_y >= -128 && screen_y < 1152)
	{
		render_floor_and_walls(game, imgs, x, y);
		render_objects1(game, imgs, x, y);
		render_objects2(game, imgs, x, y);
		render_animated_objects(game, imgs, x, y);
	}
}

void	render_map(t_game *game, t_images *imgs)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			render_tile(game, imgs, x, y);
			x++;
		}
		y++;
	}
	move_enemy(game->map, game);
	display_moves(game);
}
