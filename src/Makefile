NAME		= so_long
CC			= cc
# CFLAGS		= -Wall -Wextra -Werror -Iminilibx_opengl_20191021
MLX_FLAGS	= -framework OpenGL -framework AppKit
MLX_LIB		= ../minilibx_opengl_20191021/libmlx.a

SRCS		= main.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ../minilibx_opengl_20191021
	$(CC) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ../minilibx_opengl_20191021 clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re