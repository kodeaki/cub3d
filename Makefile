# Gigamakefile by tpirinen & jtarvain

NAME			:=	cub3d
LIBFT			:= libft/libft.a

COMPILER		:=	cc
# -Wno-incompatible-pointer-types is added to prevent compile errors on arch systems
COMPILER_FLAGS	:=	-Wall -Wextra -Werror -Wno-incompatible-pointer-types -g
INCLUDES		:=	-I./include -I./libft
MLX_DIR			:=	./include/minilibx-linux
LIBMLX			:=	$(MLX_DIR)/libmlx.a
MLXFLAGS		:=	-L$(MLX_DIR) -L./libft -lmlx -lft -lXext -lX11 -lm -lz

SRC_DIR 		:=	src
OBJ_DIR 		:=	obj

SRC				:=	main.c \
					key_presses.c \
					touch.c \
					initialization/game_init.c \
					raycasting/clear_image.c \
					parsing/utils.c \
					parsing/parse_utils.c \
					parsing/parsing.c \
					parsing/ft_open.c \
					parsing/copy.c \
					parsing/floor_ceiling.c \
					parsing/allocate.c \
					parsing/allocate_utils.c \
					parsing/safe_atoi.c \
					parsing/ft_free.c \
					parsing/parse_map.c \
					parsing/copy_map.c \
					parsing/flood_fill.c \
					player/move_player.c \
					player/get_delta_seconds.c \
					raycasting/raycast.c \
					raycasting/ray_init.c \
					raycasting/ray_dda.c \
					raycasting/texture_setup.c \
					raycasting/get_wall_texture.c \
					raycasting/draw_column.c \
					minimap/draw_map.c \
					minimap/draw_minimap.c \
					minimap/draw_player.c \
					minimap/draw_rays.c \
					minimap/put_pixel.c


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
