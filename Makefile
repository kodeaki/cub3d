
NAME			:= cub3d

COMPILER		:= cc
COMPILER_FLAGS	:= -Wall -Wextra -Werror
MLX_DIR			:= ./include/minilibx-linux
LIBMLX			:= $(MLX_DIR)/libmlx.a
MLXFLAGS		:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRC_DIR 		:= ./src/
OBJ_DIR 		:= ./obj/

SRC				:= main.c

OBJ				:= $(SRC:.c=.o)

SRCS			:= $(addprefix $(SRC_DIR), $(SRC))
OBJS			:= $(addprefix $(OBJ_DIR), $(OBJ))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBMLX)
	$(COMPILER) $(COMPILER_FLAGS) $(OBJS) $(LIBMLX) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIBMLX):
	make -C $(MLX_DIR)

clean:
	make clean -C $(MLX_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
