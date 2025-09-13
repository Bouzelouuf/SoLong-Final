/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:33:53 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/30 12:40:24 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_Map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if ((map->grid[0][i] != '1' && map->grid[0][i] != 'W' )
			|| (map->grid[map->height - 1][i] != '1'
			&& map->grid[map->height - 1][i] != 'W'))
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if ((map->grid[i][0] != '1' && map->grid[i][0] != 'W' )
			|| (map->grid[i][map->width - 1] != '1'
			&& map->grid[i][map->width - 1] != 'W'))
			return (0);
		i++;
	}
	return (1);
}
