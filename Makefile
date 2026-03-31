
NAME			:=	cub3d

COMPILER		:=	cc
COMPILER_FLAGS	:=	-Wall -Wextra -Werror
INCLUDES		:=	-I./include
MLX_DIR			:=	./include/minilibx-linux
LIBMLX			:=	$(MLX_DIR)/libmlx.a
MLXFLAGS		:=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRC_DIR 		:=	src
OBJ_DIR 		:=	obj

SRC				:=	main.c \
					put_pixel.c \
					key_presses.c \
					initialization/game_init.c \
					initialization/player_init.c \
					minimap/clear_image.c \
					minimap/draw_line.c \
					minimap/draw_loop.c \
					minimap/draw_map.c \
					minimap/draw_square.c \
					minimap/touch.c \
					parsing/map.c \
					player/move_player.c

SRCS			:=	$(addprefix $(SRC_DIR)/,$(SRC))
OBJS			:=	$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
DEPS			:=	$(OBJS:.o=.d)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX)
	$(COMPILER) $(COMPILER_FLAGS) $(OBJS) $(LIBMLX) $(MLXFLAGS) -o $(NAME)

$(LIBMLX):
	make -C $(MLX_DIR)

clean:
	make clean -C $(MLX_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
