/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:31:19 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/30 12:31:43 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_objects1(t_game *game, t_images *imgs, int x, int y)
{
	int	screen_x;
	int	screen_y;

	screen_x = (x * imgs->size) - game->camera_x;
	screen_y = (y * imgs->size) - game->camera_y;
	if (game->map->grid[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, imgs->exit,
			screen_x, screen_y);
	else if (game->map->grid[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, imgs->collect,
			screen_x, screen_y);
	else if (game->map->grid[y][x] == 'F')
		mlx_put_image_to_window(game->mlx, game->window, imgs->plante,
			screen_x, screen_y);
	else if (game->map->grid[y][x] == 'M')
		mlx_put_image_to_window(game->mlx, game->window, imgs->comode,
			screen_x, screen_y);
}

void	render_objects2(t_game *game, t_images *imgs, int x, int y)
{
	int	screen_x;
	int	screen_y;

	screen_x = (x * imgs->size) - game->camera_x;
	screen_y = (y * imgs->size) - game->camera_y;
	if (game->map->grid[y][x] == 'L')
		mlx_put_image_to_window(game->mlx, game->window, imgs->lumiere,
			screen_x, screen_y);
	else if (game->map->grid[y][x] == 'W')
		mlx_put_image_to_window(game->mlx, game->window, imgs->window,
			screen_x, screen_y);
	else if (game->map->grid[y][x] == 'T')
		mlx_put_image_to_window(game->mlx, game->window, imgs->tv,
			screen_x, screen_y);
}
