/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <abkhefif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:44:11 by abkhefif          #+#    #+#             */
/*   Updated: 2025/09/13 17:17:02 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

# define TILE_SIZE 128

typedef struct s_map
{
	int				width;
	int				height;
	char			**grid;
	int				start_pos[2];
	int				exit_pos[2];
	int				collectible_count;
	int				i;
	int				enemy_x;
	int				enemy_y;
	int				new_y;
	int				new_x;
}	t_Map;

typedef struct s_images
{
	void			*wall;
	void			*floor;
	void			*floor2;
	void			*tv;
	void			*mom;
	void			*window;
	void			*plante;
	void			*lumiere;
	void			*comode;
	void			*player_move_right[7];
	void			*player_move_left[7];
	void			*collect;
	void			*exit;
	int				size;
	void			*cat[2];
	void			*game_over;
}	t_images;

typedef enum s_game_state
{
	GAME_RUNNING,
	GAME_OVER
}	t_game_state;

typedef struct s_sprite_sheet
{
	void			*img;
	int				width;
	int				height;
	int				frame_width;
	int				frame_count;
	int				current_frame;
	int				*data;
}	t_sprite_sheet;

typedef struct s_game
{
	int				player_direction;
	t_Map			*map;
	int				player_x;
	int				player_y;
	int				moves;
	int				collected;
	void			*mlx;
	void			*window;
	int				frame;
	int				cat_frame;
	t_images		imgs;
	t_sprite_sheet	decor;
	int				enemy_x;
	int				enemy_y;
	t_game_state	state;
	int				camera_y;
	int				camera_x;
}	t_game;

# define UP      1
# define DOWN    2
# define LEFT    3
# define RIGHT   4

int		animate_sprite(t_game *game);
void	init_sprite_animation(t_game *game, t_sprite_sheet *sprite, char *path,
			int nb_frames);
int		setup_game(t_game *game);
int		init_images(t_game *game, t_images *imgs);
void	render_map(t_game *game, t_images *imgs);
int		check_elements(t_Map *map);
int		check_file_extension(char *filename);
int		check_line_lengths(char *filename, int *width);
int		check_walls(t_Map *map);
int		count_map_lines(char *filename);
int		fill_map_data(t_Map *map, char *filename);
t_Map	*init_map_structure(int height, int width);
t_Map	*load_map(char *filename);
void	free_map(t_Map *map);
int		move_player(t_game *game, int direction);
t_game	*init_game(t_Map *map);
int		handle_keypress(int keycode, t_game *game);
int		collect_item(t_game *game);
int		check_win(t_game *game);
int		find_player(t_Map *map);
void	display_moves(t_game *game);
void	move_enemy(t_Map *map, t_game *game);
int		find_enemy_pos(t_Map *map);
int		game_state_handler(t_game *game);
int		close_window(t_game *game);
void	update_camera(t_game *game);
void	render_objects1(t_game *game, t_images *imgs, int x, int y);
void	render_objects2(t_game *game, t_images *imgs, int x, int y);
int		init_cat_images(t_game *game, t_images *imgs, char **chat);
void	flood_fill(char **copymap, t_Map *map, int x, int y);
int		check_path(t_Map *map);
int		check_collectibles(t_Map *map, char **copymap);

#endif
