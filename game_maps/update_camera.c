/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:37:24 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/30 12:38:23 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_camera(t_game *game)
{
	int	new_camera_x;
	int	new_camera_y;
	int	max_camera_x;
	int	max_camera_y;

	new_camera_x = (game->player_x * 128) - (1920 / 2);
	new_camera_y = (game->player_y * 128) - (1152 / 2);
	if (new_camera_x < 0)
		new_camera_x = 0;
	if (new_camera_y < 0)
		new_camera_y = 0;
	max_camera_x = (game->map->width * 128) - 1920;
	max_camera_y = (game->map->height * 128) - 1152;
	if (new_camera_x > max_camera_x)
		new_camera_x = max_camera_x;
	if (new_camera_y > max_camera_y)
		new_camera_y = max_camera_y;
	game->camera_x = new_camera_x;
	game->camera_y = new_camera_y;
}
