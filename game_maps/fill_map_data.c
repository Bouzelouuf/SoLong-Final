/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:22:13 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/28 11:36:36 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	process_element(char line, t_Map *map, int i, int j)
{
	if (line == 'C')
		map->collectible_count++;
	if (line == 'P')
	{
		map->start_pos[0] = j;
		map->start_pos[1] = i;
	}
	if (line == 'E')
	{
		map->exit_pos[0] = j;
		map->exit_pos[1] = i;
	}
	if (line == 'K')
	{
		map->enemy_x = j;
		map->enemy_y = i;
	}
}

int	fill_map_data(t_Map *map, char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (line[j])
		{
			process_element(line[j], map, i, j);
			j++;
		}
		map->grid[i] = line;
		i++;
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}
