# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 15:02:50 by kclaudan          #+#    #+#              #
#    Updated: 2024/11/14 15:02:50 by kclaudan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c \
		./ft_isdigit.c ./ft_isprint.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c \
		./ft_memset.c ./ft_strchr.c ./ft_strdup.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c \
		./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_tolower.c ./ft_toupper.c ./ft_substr.c \
		./ft_strjoin.c ./ft_strtrim.c ./ft_split.c  ./ft_putchar_fd.c ./ft_putendl_fd.c \
		./ft_putstr_fd.c ./ft_putnbr_fd.c ./ft_itoa.c ./ft_strmapi.c ./ft_striteri.c

BONUS = ./ft_lstnew_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstsize_bonus.c ./ft_lstlast_bonus.c \
 		./ft_lstadd_back_bonus.c ./ft_lstdelone_bonus.c ./ft_lstclear_bonus.c ./ft_lstiter_bonus.c \
		./ft_lstmap_bonus.c

NAME = libft.a

AR = ar -rcs

# Transforme chaques fichiers .c en .o
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

# Name est la cible que je defini.
# Elle depend de OBJ (verif si le contenu de obj est a jour) et execute linstruction
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

# Insturction pour re compiler un fichier non mis a jour,
# Cest une regle implicite par defaut personnaliser
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus: $(NAME) $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)

clean: 
	rm -rf $(OBJ) $(BONUS:.c=.o)

fclean: clean
	rm -rf $(NAME)

re: fclean all
