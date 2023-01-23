#quando mato um among us, spawna um enimigo como ghost among us

NAME = so_long

CC = cc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

SRC = map_check.c main.c keys.c utils.c window.c animations.c end_screens.c

GNL_SRC = get_next_line_utils.c get_next_line.c

SRC_OBJ = $(SRC:.c=.o)

GNL_OBJ = $(GNL_SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "\n\nCompiling the game files...\n"
	@make -s -C mlx_linux
	@$(CC) -g $(FLAGS) $(SRC) $(addprefix GNL/,$(GNL_SRC)) mlx_linux/libmlx_Linux.a -lXext -lX11 -o $(NAME)

map1:
	@echo "\nChecking map components..."
	@echo "\n------------------"
	@./so_long maps/map1.ber

map2:
	@echo "\nChecking map components..."
	@echo "\n------------------"
	@./so_long maps/map2.ber

map3:
	@echo "\nChecking map components..."
	@echo "\n------------------"
	@./so_long maps/map3.ber

clean:
	@find . -type f \( -name "*.o" \) -delete

fclean: clean
	@find . -type f \( -name "*.a" -o -name "so_long" \) -delete

re: fclean all

valgrind:	all
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./so_long maps/map3.ber
