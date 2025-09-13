/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <abkhefif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:13:00 by abkhefif          #+#    #+#             */
/*   Updated: 2025/09/13 17:40:10 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_obstacle(char c)
{
	return (c == '1' || c == 'W' || c == 'F' || c == 'L'
		|| c == 'M' || c == 'T' || c == 'K' || c == 'Z');
}

static void	update_player_position(t_game *game, int next_x,
		int next_y, char next_cell)
{
	if (game->map->grid[game->player_y][game->player_x] != 'E')
		game->map->grid[game->player_y][game->player_x] = '3';
	if (next_cell != 'E')
		game->map->grid[next_y][next_x] = 'P';
	game->player_x = next_x;
	game->player_y = next_y;
	game->moves++;
}

int	move_player(t_game *game, int direction)
{
	int		next_x;
	int		next_y;
	char	next_cell;

	game->player_direction = direction;
	next_x = game->player_x;
	next_y = game->player_y;
	if (direction == UP)
		next_y = game->player_y - 1;
	else if (direction == DOWN)
		next_y = game->player_y + 1;
	else if (direction == LEFT)
		next_x = game->player_x - 1;
	else if (direction == RIGHT)
		next_x = game->player_x + 1;
	if (is_obstacle(game->map->grid[next_y][next_x]))
		return (0);
	if (game->map->grid[next_y][next_x] == 'C')
		game->collected++;
	next_cell = game->map->grid[next_y][next_x];
	update_player_position(game, next_x, next_y, next_cell);
	render_map(game, &game->imgs);
	return (1);
}
