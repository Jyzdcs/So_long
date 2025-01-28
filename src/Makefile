NAME		= so_long
CC			= cc
# CFLAGS		= -Wall -Wextra -Werror -Iminilibx_opengl_20191021
MLX_FLAGS	= -framework OpenGL -framework AppKit
MLX_LIB		= ../minilibx_opengl_20191021/libmlx.a
LIBFT		= ../includes/libft/libft.a
GNL		= ../includes/libft/get_next_line.a

SRCS		= main.c movements_handler.c filler.c parsing.c enemies_handler.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ../minilibx_opengl_20191021
	$(MAKE) -C ../includes/libft
	$(CC) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) $ -o $(NAME) -g

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ../minilibx_opengl_20191021 clean
	$(MAKE) -C ../includes/libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ../includes/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re