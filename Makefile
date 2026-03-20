
NAME			:= cub3d

COMPILER		:= cc

COMPILER_FLAGS	:= -Wall -Wextra -Werror

SRC_DIR 	=	./src/
OBJ_DIR 	=	./obj/

SRC				:= 
OBJ				:= $(SRC:.cpp=.o)

SRCS		=	$(addprefix $(SRC_DIR), $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(COMPILER_FLAGS) $^ -o $(NAME)

%.o: %.cpp
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
