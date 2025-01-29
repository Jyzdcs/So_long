NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx_linux
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz
LIBFT = ../includes/libft/libft.a

SRCS = main.c movements_handler.c filler.c parsing.c enemies_handler.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ../minilibx_opengl_20191021
	$(CC) $(OBJS) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
