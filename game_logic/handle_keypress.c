/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <abkhefif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:03:36 by abkhefif          #+#    #+#             */
/*   Updated: 2025/09/13 17:19:45 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_movement(t_game *game)
{
	collect_item(game);
	if (check_win(game))
	{
		ft_printf("Well play, you win in %d movements", game->moves);
		exit(0);
	}
	update_camera(game);
	render_map(game, &game->imgs);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
	if ((keycode == 65362 || keycode == 119) && move_player(game, UP))
		handle_movement(game);
	if ((keycode == 65364 || keycode == 115) && move_player(game, DOWN))
		handle_movement(game);
	if ((keycode == 65361 || keycode == 97) && move_player(game, LEFT))
		handle_movement(game);
	if ((keycode == 65363 || keycode == 100) && move_player(game, RIGHT))
		handle_movement(game);
	return (0);
}
