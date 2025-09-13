/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:50:05 by abkhefif          #+#    #+#             */
/*   Updated: 2025/02/15 15:36:04 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./minilibx/mlx.h"

static int	init_and_setup_game(t_game **game, t_Map *map)
{
	ft_printf("Initializing game...\n");
	*game = init_game(map);
	if (!*game)
	{
		ft_printf("Error: Game initialization failed\n");
		return (0);
	}
	ft_printf("Setting up game...\n");
	if (!setup_game(*game))
	{
		ft_printf("Error: Game setup failed\n");
		free(*game);
		return (0);
	}
	return (1);
}

static int	check_map(t_Map *map)
{
	if (!check_walls(map))
	{
		ft_printf("Error: Invalid walls\n");
		return (0);
	}
	if (!check_elements(map))
	{
		ft_printf("Error: Invalid elements\n");
		return (0);
	}
	if (!find_player(map))
	{
		ft_printf("Error: Player not found\n");
		return (0);
	}
	if (!check_path(map))
	{
		ft_printf("Error: No valid path found in map\n");
		return (0);
	}
	return (1);
}

static int	free_return(t_Map *map)
{
	free_map(map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_Map	*map;

	if (argc != 2)
		return (1);
	if (!check_file_extension(argv[1]))
		return (1);
	ft_printf("Loading map...\n");
	map = load_map(argv[1]);
	if (!map)
	{
		ft_printf("Error : Map not found");
		return (1);
	}
	if (!check_map(map))
		return (free_return(map));
	if (!find_enemy_pos(map))
		return (free_return(map));
	if (!init_and_setup_game(&game, map))
		return (free_return(map));
	mlx_loop(game->mlx);
	free_map(map);
	free(game);
	return (0);
}
