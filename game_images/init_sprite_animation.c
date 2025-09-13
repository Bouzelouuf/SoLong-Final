/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:21:30 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/11 23:04:53 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite_animation(t_game *game, t_sprite_sheet *sprite,
char *path, int nb_frames)
{
	int		w;
	int		h;

	sprite->img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	sprite->width = w;
	sprite->height = h;
	sprite->frame_count = nb_frames;
	sprite->frame_width = w / nb_frames;
	sprite->current_frame = 0;
}
