
NAME			:= cub3d

COMPILER		:= cc
COMPILER_FLAGS	:= -Wall -Wextra -Werror
LFLAGS			:= -L./include/mlx -lmlx -lXext -lX11 -lm -lz
LIBMLX			:= include/mlx/libmlx.a

SRC_DIR 		:= ./src/
OBJ_DIR 		:= ./obj/

SRC				:= main.c

OBJ				:= $(SRC:.c=.o)

SRCS			:= $(addprefix $(SRC_DIR), $(SRC))
OBJS			:= $(addprefix $(OBJ_DIR), $(OBJ))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

all: $(NAME) $(LIBMLX)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(COMPILER) $(COMPILER_FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIBMLX):
	make -C include/minilibx-linux/

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
