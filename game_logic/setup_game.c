/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:23:25 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/30 11:40:35 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	setup_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Failed to initialize MLX\n");
		return (0);
	}
	game->window = mlx_new_window(game->mlx, 1920,
			1152, "so_long");
	if (!game->window)
	{
		ft_printf("Failed to create window\n");
		return (0);
	}
	if (!init_images(game, &game->imgs))
	{
		ft_printf("Failed to load images\n");
		return (0);
	}
	update_camera(game);
	render_map(game, &game->imgs);
	mlx_hook(game->window, 2, 1L << 0, handle_keypress, game);
	init_sprite_animation(game, &game->decor, "sprites/zafyr.xpm", 10);
	mlx_loop_hook(game->mlx, animate_sprite, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	return (1);
}
