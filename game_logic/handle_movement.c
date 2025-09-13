/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:28:44 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/11 19:29:18 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_movement(t_game *game)
{
	collect_item(game);
	if (check_win(game))
	{
		ft_printf("Well play, you win in %d movements", game->moves);
		exit(0);
	}
	render_map(game, &game->imgs);
}
