/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:05:21 by abkhefif          #+#    #+#             */
/*   Updated: 2025/02/15 15:12:06 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_exit(t_Map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'E')
			{
				map->exit_pos[0] = x;
				map->exit_pos[1] = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	flood_fill(char **copymap, t_Map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (copymap[y][x] == '1' || copymap[y][x] == 'M'
			|| copymap[y][x] == 'T' || copymap[y][x] == 'F'
			|| copymap[y][x] == 'K' || copymap[y][x] == 'Z'
			|| copymap[y][x] == 'V' || copymap[y][x] == 'W')
		return ;
	copymap[y][x] = 'V';
	flood_fill(copymap, map, x, y + 1);
	flood_fill(copymap, map, x, y - 1);
	flood_fill(copymap, map, x + 1, y);
	flood_fill(copymap, map, x - 1, y);
}

void	free_copymap(char **copymap)
{
	int	i;

	i = 0;
	while (copymap[i])
		free(copymap[i++]);
	free(copymap);
}

int	check_collectibles(t_Map *map, char **copymap)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'C' && copymap[i][j] != 'V')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(t_Map *map)
{
	char	**copymap;
	int		i;

	i = 0;
	find_exit(map);
	copymap = malloc(sizeof(char *) * (map->height + 1));
	if (!copymap)
		return (0);
	while (i < map->height)
	{
		copymap[i] = ft_strdup(map->grid[i]);
		i++;
	}
	copymap[i] = NULL;
	flood_fill(copymap, map, map->start_pos[0], map->start_pos[1]);
	if (copymap[map->exit_pos[1]][map->exit_pos[0]] != 'V'
			|| !check_collectibles(map, copymap))
	{
		free_copymap(copymap);
		return (0);
	}
	free_copymap(copymap);
	return (1);
}
