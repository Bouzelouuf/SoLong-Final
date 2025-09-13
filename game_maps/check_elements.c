/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:32:01 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/11 19:45:44 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_cell(char cell, int *p_count, int *e_count, int *c_count)
{
	if (cell == 'P')
		(*p_count)++;
	else if (cell == 'E')
		(*e_count)++;
	else if (cell == 'C')
		(*c_count)++;
}

int	check_elements(t_Map *map)
{
	int	player_count;
	int	exit_count;
	int	collect_count;
	int	i;
	int	j;

	player_count = 0;
	exit_count = 0;
	collect_count = 0;
	i = -1;
	while (++i < map->height)
	{
		j = 0;
		while (j < map->width && ++j)
			check_cell(map->grid[i][j], &player_count,
				&exit_count, &collect_count);
	}
	map->collectible_count = collect_count;
	if (player_count != 1 || exit_count != 1 || collect_count < 1)
		return (0);
	return (1);
}
