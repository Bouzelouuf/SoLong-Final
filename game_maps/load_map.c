/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:05:43 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/30 12:39:05 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_Map	*load_map(char *filename)
{
	int		fd;
	char	*line;
	int		width;
	t_Map	*map;
	int		height;

	height = count_map_lines(filename);
	if (height <= 0 || !check_line_lengths(filename, &width))
		return (NULL);
	map = init_map_structure(height, width);
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free_map(map);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		map->grid[map->i++] = line;
		line = get_next_line(fd);
	}
	return (close(fd), map);
}
