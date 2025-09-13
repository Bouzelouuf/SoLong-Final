/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:27:38 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/30 11:46:52 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_obstacle(char c)
{
	return (c == '1' || c == 'W' || c == 'F' || c == 'L'
		|| c == 'M' || c == 'T' || c == 'K' || c == 'Z'
		|| c == 'C' || c == 'E');
}

static void	update_enemy_position(t_Map *map, int old_x, int old_y)
{
	map->grid[old_y][old_x] = '0';
	map->grid[map->new_y][map->new_x] = 'K';
	map->enemy_x = map->new_x;
	map->enemy_y = map->new_y;
}

static void	display_game_over(t_game *game)
{
	int	img_width;
	int	img_height;

	game->state = GAME_OVER;
	game->imgs.game_over = mlx_xpm_file_to_image(game->mlx,
			"./sprites/game_over.xpm", &img_width, &img_height);
	if (!game->imgs.game_over)
		return ;
	ft_printf("Game Over!");
	mlx_put_image_to_window(game->mlx, game->window, game->imgs.game_over,
		0, 0);
	mlx_do_sync(game->mlx);
	usleep(3000000);
	close_window(game);
	mlx_loop_end(game->mlx);
}

void	move_enemy(t_Map *map, t_game *game)
{
	int	dx;
	int	dy;

	dx = (rand() % 3) - 1;
	dy = (rand() % 3) - 1;
	map->new_y = map->enemy_y + dy;
	map->new_x = map->enemy_x + dx;
	if (map->new_x >= 0 && map->new_x < map->width
		&& map->new_y >= 0 && map->new_y < map->height
		&& !is_obstacle(map->grid[map->new_y][map->new_x]))
	{
		update_enemy_position(map, map->enemy_x, map->enemy_y);
	}
	if (map->enemy_x == game->player_x && map->enemy_y == game->player_y)
		display_game_over(game);
}
