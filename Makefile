# Gigamakefile by tpirinen & jtarvain

NAME			:=	cub3d
LIBFT			:= libft/libft.a

COMPILER		:=	cc
# -Wno-incompatible-pointer-types is added to prevent compile errors on arch systems
COMPILER_FLAGS	:=	-Wall -Wextra -Werror -Wno-incompatible-pointer-types
INCLUDES		:=	-I./include -I./libft
MLX_DIR			:=	./include/minilibx-linux
LIBMLX			:=	$(MLX_DIR)/libmlx.a
MLXFLAGS		:=	-L$(MLX_DIR) -L./libft -lmlx -lft -lXext -lX11 -lm -lz

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
					minimap/draw_minimap.c\
					minimap/draw_player.c \
					minimap/draw_square.c \
					minimap/touch.c \
					parsing/map.c \
					parsing/utils.c \
					parsing/parsing.c \
					player/move_player.c

SRCS			:=	$(addprefix $(SRC_DIR)/,$(SRC))
OBJS			:=	$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
DEPS			:=	$(OBJS:.o=.d)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX) $(LIBFT)
	$(COMPILER) $(COMPILER_FLAGS) $(OBJS) $(LIBMLX) $(MLXFLAGS) -o $(NAME)

$(LIBMLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C libft/

clean:
	make clean -C $(MLX_DIR)
	make clean -C libft/
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(LIBMLX)
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
