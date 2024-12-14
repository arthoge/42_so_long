CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

MLX_DIR = minilibx-linux
LIBMLX = -L$(MLX_DIR) -lmlx -lX11 -lXext -lbsd

G_LIBFT_DIR = g_libft
LIBFT = -L$(G_LIBFT_DIR) -lft

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

SRC =	src/main.c \
		src/init_game.c \
		src/handle_mlx.c \
		src/load_map.c \
		src/check_map.c \
		src/check_valid_path.c \
		src/load_assets.c \
		src/render.c \
		src/handle_events.c \
		src/move_hero.c \
		src/utils.c \
		src/init_enemy_bonus.c \
		src/move_enemy_bonus.c

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(G_LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(OBJ) $(LIBMLX) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(G_LIBFT_DIR)
	make clean -C $(MLX_DIR) 
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(G_LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re