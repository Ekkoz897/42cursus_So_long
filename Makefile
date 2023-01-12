NAME = so_long.a

CC = cc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

SRC = map_check.c keys.c vars_init.c window.c

GNL_SRC = get_next_line_utils.c get_next_line.c

MAP_SRC = map.ber

GNL_OBJ = $(GNL_SRC:.c=.o)


all: $(NAME)

$(NAME): #$(GNL_OBJ)
	$(CC) $(FLAGS) main.c $(SRC) $(addprefix GNL/,$(GNL_SRC)) mlx_linux/libmlx_Linux.a -lXext -lX11

run:	all
	./a.out $(addprefix maps/,$(MAP_SRC))
