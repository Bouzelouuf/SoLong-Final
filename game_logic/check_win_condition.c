/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win_condition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:01:19 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/11 19:02:04 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_win(t_game *game)
{
	if (game->map->grid[game->player_y][game->player_x] == 'E')
	{
		if (game->collected == game->map->collectible_count)
			return (1);
	}
	return (0);
}
