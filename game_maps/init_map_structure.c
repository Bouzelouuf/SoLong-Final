/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:16:45 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/11 21:18:55 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_Map	*init_map_structure(int height, int width)
{
	t_Map	*map;

	map = malloc(sizeof(t_Map));
	if (!map)
		return (NULL);
	map->grid = malloc(sizeof(char *) * (height * width));
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	map->height = height;
	map->width = width;
	map->collectible_count = 0;
	map->start_pos[0] = -1;
	map->start_pos[1] = -1;
	map->exit_pos[0] = -1;
	map->exit_pos[1] = -1;
	map->i = 0;
	return (map);
}
