/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:23:25 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/28 11:25:12 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check(long n)
{
	int	tot;

	tot = 0;
	if (n < 0)
	{
		n *= -1;
		tot++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		tot++;
	}
	return (tot);
}

static char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	long	nb;

	nb = n;
	i = check(nb);
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	dest[i--] = '\0';
	if (nb == 0)
		return (dest[0] = '0', dest);
	if (nb < 0)
	{
		dest[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		dest[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (dest);
}

void	display_moves(t_game *game)
{
	char	*moves_str;
	char	*prefix;

	prefix = "Mouvements:    ";
	moves_str = ft_itoa(game->moves);
	mlx_set_font(game->mlx, game->window, "12X24");
	mlx_string_put(game->mlx, game->window, 1700, 1100, 0xFFFFFF, prefix);
	mlx_string_put(game->mlx, game->window, 1850, 1100, 0xFFFFFF, moves_str);
	free(moves_str);
}
