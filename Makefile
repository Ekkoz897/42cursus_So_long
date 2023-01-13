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
	$(CC) -g $(FLAGS) $(SRC) $(addprefix GNL/,$(GNL_SRC)) mlx_linux/libmlx_Linux.a -lXext -lX11 -o $(NAME)

valgrind:	all
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./so_long $(addprefix maps/,$(MAP_SRC))

run:	all
	./so_long $(addprefix maps/,$(MAP_SRC))

clean:
	rm -f so_long
