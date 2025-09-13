NAME = so_long

SRCS_MAPS = game_maps/check_file_extension.c \
            game_maps/check_elements.c \
            game_maps/check_line_lengths.c \
            game_maps/check_walls.c \
            game_maps/count_map_lines.c \
            game_maps/fill_map_data.c \
            game_maps/free_map.c \
            game_maps/init_map_structure.c \
            game_maps/load_map.c\
            game_maps/find_player.c \
            game_maps/find_enemy_pos.c \
            game_maps/update_camera.c

SRCS_LOGIC = game_logic/init_game.c \
             game_logic/move_player.c \
             game_logic/handle_keypress.c \
             game_logic/collect_item.c \
             game_logic/check_win_condition.c \
             game_logic/setup_game.c \
             game_logic/move_enemy.c \
             game_logic/game_state_handler.c \
             game_logic/close_window.c \
             game_logic/flood_fill.c


SRCS_IMAGE = game_images/init_images.c \
             game_images/render_map.c \
             game_images/init_sprite_animation.c \
             game_images/animate_sprite.c \
             game_images/display_moves.c \
             game_images/render_objects.c \
             game_images/init_cat_images.c

SRCS_GNL = get_next_line/get_next_line.c \
           get_next_line/get_next_line_utils.c

MLX_DIR = minilibx
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11

SRCS = main.c $(SRCS_MAPS) $(SRCS_LOGIC) $(SRCS_IMAGE) $(SRCS_GNL)

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I./minilibx -I./get_next_line -D BUFFER_SIZE=42
LIBFT = -L./libft -lft
FT_PRINTF = -L./ft_printf -lftprintf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C ./ft_printf
	$(CC) $(OBJS) $(MLX) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
