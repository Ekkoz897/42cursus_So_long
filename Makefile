NAME = so_long.a

CC = cc

RM = rm -f

SRC = map_check.c keys.c vars_init.c window.c

GNL_SRC = get_next_line_utils.c get_next_line.c

LIBFT_RC = ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_striteri.c \
		ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_itoa.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c

MAP_SRC = map.ber

GNL_OBJ = $(GNL_SRC:.c=.o)

all:

	$(CC) main.c $(SRC) $(addprefix libft/,$(LIBFT_SRC)) $(addprefix GNL/,$(GNL_SRC)) libmlx_Linux.a -lXext -lX11

run:	all
	./a.out $(addprefix maps/,$(MAP_SRC))
