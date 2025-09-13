/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <abkhefif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:49:58 by abkhefif          #+#    #+#             */
/*   Updated: 2025/09/13 17:34:08 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	util_close(t_game *game)
{
	if (game->imgs.wall)
		mlx_destroy_image(game->mlx, game->imgs.wall);
	if (game->imgs.floor)
		mlx_destroy_image(game->mlx, game->imgs.floor);
	if (game->imgs.exit)
		mlx_destroy_image(game->mlx, game->imgs.exit);
	if (game->imgs.collect)
		mlx_destroy_image(game->mlx, game->imgs.collect);
	if (game->imgs.floor2)
		mlx_destroy_image(game->mlx, game->imgs.floor2);
}

int	close_window(t_game *game)
{
	int	i;

	i = 0;
	mlx_loop_hook(game->mlx, NULL, NULL);
	while (i < 7)
	{
		if (game->imgs.player_move_right[i])
		{
			mlx_destroy_image(game->mlx, game->imgs.player_move_right[i]);
			game->imgs.player_move_right[i] = NULL;
		}
		i++;
	}
	i = 0;
	while (i < 7)
	{
		if (game->imgs.player_move_left[i])
		{
			mlx_destroy_image(game->mlx, game->imgs.player_move_left[i]);
			game->imgs.player_move_left[i] = NULL;
		}
		i++;
	}
	if (game->mlx)
		util_close(game);
	if (game->window)
	{
		mlx_destroy_window(game->mlx, game->window);
		game->window = NULL;
	}
	if (game->map)
		free_map(game->map);
	exit(0);
	return (0);
}
