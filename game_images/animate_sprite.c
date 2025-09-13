/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:42:49 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/11 21:46:01 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animate_sprite(t_game *game)
{
	static int	delay;

	delay++;
	if (delay < 40000)
		return (0);
	delay = 0;
	game->decor.current_frame = (game->decor.current_frame + 1)
		% game->decor.frame_count;
	render_map(game, &game->imgs);
	return (0);
}
