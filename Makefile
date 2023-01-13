NAME = so_long

CC = cc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

SRC = map_check.c main.c keys.c vars_init.c window.c

GNL_SRC = get_next_line_utils.c get_next_line.c

MAP_SRC = map.ber

SRC_OBJ = $(SRC:.c=.o)

GNL_OBJ = $(GNL_SRC:.c=.o)


all: $(NAME)

$(NAME):
	@echo "\nCompiling the game files...\n"
	@make -s -C mlx_linux
	@$(CC) -g $(FLAGS) $(SRC) $(addprefix GNL/,$(GNL_SRC)) mlx_linux/libmlx_Linux.a -lXext -lX11 -o $(NAME)

run:
	@echo "\nLoading the map"
	@echo "\n------------------"
	@./so_long $(addprefix maps/,$(MAP_SRC))

clean:
	@find . -type f \( -name "*.o" \) -delete

fclean: clean
	@find . -type f \( -name "*.a" -o -name "so_long" \) -delete

re: fclean all

valgrind:	all
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./so_long $(addprefix maps/,$(MAP_SRC))
