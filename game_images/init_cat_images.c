/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cat_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:58:20 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/31 14:58:21 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_cat_images(t_game *game, t_images *imgs, char **chat)
{
	int		img_width;
	int		img_height;
	int		y;
	int		j;

	j = 0;
	y = 0;
	while (y < 2)
	{
		imgs->cat[y] = mlx_xpm_file_to_image(game->mlx, chat[y],
				&img_width, &img_height);
		if (!imgs->cat[y])
		{
			while (j < y)
			{
				if (imgs->cat[j])
					mlx_destroy_image(game->mlx, imgs->cat[j]);
				j++;
			}
			return (0);
		}
		y++;
	}
	return (1);
}
