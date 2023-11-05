NAME = so_long

MLX = minilibx/libmlx.a

PRINTF = ft_printf/libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -O3

SRC = src/main.c src/matrix.c src/split.c src/check.c src/read.c \
	  src/image.c src/flood.c src/play.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(MLX):
	make -C ./minilibx

$(PRINTF):
	make -C ./ft_printf

$(NAME): $(OBJ) $(MLX)
	$(CC) $(FLAGS) $(MLX_FLAGS) $(SRC) $(MLX) $(PRINTF) -o $(NAME)

clean: 
	rm -f ${OBJ}

fclean: clean
	rm -f $(NAME)
	
re: fclean all