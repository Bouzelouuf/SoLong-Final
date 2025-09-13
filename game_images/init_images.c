/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 23:34:21 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/30 13:13:10 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_player_images(t_game *game, t_images *imgs, char **players_move)
{
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < 7)
	{
		imgs->player[i] = mlx_xpm_file_to_image(game->mlx, players_move[i],
				&img_width, &img_height);
		if (!imgs->player[i])
		{
			while (j < i)
			{
				mlx_destroy_image(game->mlx, imgs->player[j]);
				j++;
			}
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_basic_images(t_game *game, t_images *imgs)
{
	int		img_width;
	int		img_height;

	imgs->wall = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm",
			&img_width, &img_height);
	imgs->floor = mlx_xpm_file_to_image(game->mlx, "./sprites/floor.xpm",
			&img_width, &img_height);
	imgs->collect = mlx_xpm_file_to_image(game->mlx, "./sprites/collect.xpm",
			&img_width, &img_height);
	imgs->exit = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm",
			&img_width, &img_height);
	if (!imgs->wall || !imgs->floor || !imgs->collect || !imgs->exit)
	{
		if (imgs->wall)
			mlx_destroy_image(game->mlx, imgs->wall);
		if (imgs->floor)
			mlx_destroy_image(game->mlx, imgs->floor);
		if (imgs->collect)
			mlx_destroy_image(game->mlx, imgs->collect);
		if (imgs->exit)
			mlx_destroy_image(game->mlx, imgs->exit);
		return (0);
	}
	return (1);
}

int	destroy_extra_images(t_game *game, t_images *imgs)
{
	if (imgs->tv)
		mlx_destroy_image(game->mlx, imgs->tv);
	if (imgs->mom)
		mlx_destroy_image(game->mlx, imgs->mom);
	if (imgs->window)
		mlx_destroy_image(game->mlx, imgs->window);
	if (imgs->floor2)
		mlx_destroy_image(game->mlx, imgs->floor2);
	if (imgs->plante)
		mlx_destroy_image(game->mlx, imgs->plante);
	if (imgs->lumiere)
		mlx_destroy_image(game->mlx, imgs->lumiere);
	if (imgs->comode)
		mlx_destroy_image(game->mlx, imgs->comode);
	return (0);
}

int	init_extra_images(t_game *game, t_images *imgs)
{
	int		img_width;
	int		img_height;

	imgs->tv = mlx_xpm_file_to_image(game->mlx, "./sprites/tv.xpm",
			&img_width, &img_height);
	imgs->mom = mlx_xpm_file_to_image(game->mlx, "./sprites/mom.xpm",
			&img_width, &img_height);
	imgs->window = mlx_xpm_file_to_image(game->mlx, "./sprites/window.xpm",
			&img_width, &img_height);
	imgs->floor2 = mlx_xpm_file_to_image(game->mlx, "./sprites/floor2.xpm",
			&img_width, &img_height);
	imgs->plante = mlx_xpm_file_to_image(game->mlx, "./sprites/plante.xpm",
			&img_width, &img_height);
	imgs->lumiere = mlx_xpm_file_to_image(game->mlx, "./sprites/lumiere.xpm",
			&img_width, &img_height);
	imgs->comode = mlx_xpm_file_to_image(game->mlx, "./sprites/comode.xpm",
			&img_width, &img_height);
	if (!imgs->tv || !imgs->mom || !imgs->window || !imgs->floor2
		|| !imgs->plante || !imgs->lumiere || !imgs->comode)
	{
		destroy_extra_images(game, imgs);
		return (0);
	}
	return (1);
}

int	init_images(t_game *game, t_images *imgs)
{
	char	*chat[5];
	char	*players_move[7];

	players_move[0] = "./sprites/move/move.xpm";
	players_move[1] = "./sprites/move/move(1).xpm";
	players_move[2] = "./sprites/move/move(2).xpm";
	players_move[3] = "./sprites/move/move(3).xpm";
	players_move[4] = "./sprites/move/move(4).xpm";
	players_move[5] = "./sprites/move/move(5).xpm";
	players_move[6] = "./sprites/move/move(6).xpm";
	chat[0] = "./sprites/zafyr/cat.xpm";
	chat[1] = "./sprites/zafyr/cat(1).xpm";
	imgs->size = 128;
	if (!init_player_images(game, imgs, players_move)
		|| !init_cat_images(game, imgs, chat)
		|| !init_basic_images(game, imgs) || !init_extra_images(game, imgs))
		return (0);
	return (1);
}
