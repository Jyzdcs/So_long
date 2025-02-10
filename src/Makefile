NAME		= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Imlx_linux
MLX_FLAGS	= -Lmlx_linux -lXext -lX11 -lm -lz
MLX_LIB	= ../minilibx-linux/libmlx.a
LIBFT		= ../includes/libft/libft.a
GNL		= ../includes/libft/get_next_line.a

SRCS		= main.c movements_handler.c filler.c parsing.c enemies_handler.c texture_handler.c \
		window_handler.c init_game.c utils.c backtracking.c backtracking_utils.c \
		enemies_handler_utils.c init.c movements_handler_utils.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ../minilibx-linux/
	$(MAKE) -C ../includes/libft
	$(CC) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME) -g

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(MAKE) -C ../includes/libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ../includes/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
