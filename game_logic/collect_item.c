/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:03:08 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/11 19:03:24 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collect_item(t_game *game)
{
	if (game->map->grid[game->player_y][game->player_x] == 'C')
	{
		game->map->grid[game->player_y][game->player_x] = '0';
		game->collected++;
		return (1);
	}
	return (0);
}
