/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:27:08 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/30 11:47:17 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(t_Map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = map;
	game->player_x = map->start_pos[0];
	game->player_y = map->start_pos[1];
	game->collected = 0;
	game->moves = 0;
	game->mlx = NULL;
	game->window = NULL;
	game->frame = 0;
	game->cat_frame = 0;
	game->camera_x = game->player_x * 128 - (1920 / 2);
	game->camera_y = game->player_y * 128 - (1152 / 2);
	return (game);
}
