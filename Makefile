NAME = fractol
NAME_SOURCES = main.c image.c mouse_hook.c init.c fractols.c key_hook.c draw.c color.c menu.c
PATH_SRCS = ./srcs/
SRC = $(addprefix $(PATH_SRCS),$(NAME_SOURCES))
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
INCLUDE = ./includes

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft/
	@make -C minilibx_macos/
	@gcc $(FLAGS) -o $(NAME) $(SRC) -I$(INCLUDE) -L. libft/libft.a -lm -pthread minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re