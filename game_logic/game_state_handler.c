/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:47:45 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/30 11:49:00 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_state_handler(t_game *game)
{
	static int	delay;

	delay = 0;
	if (game->state == GAME_OVER)
	{
		delay++;
		if (delay > 10000)
		{
			mlx_destroy_window(game->mlx, game->window);
		}
		exit(0);
	}
	return (0);
}
