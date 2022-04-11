# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 12:56:26 by mviinika          #+#    #+#              #
#    Updated: 2022/04/10 21:30:51 by mviinika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
	formats.c length.c \
	flags.c treat_with_mods.c \
	init_struct.c check_edges.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = clang

FLAGS = -c -Wall -Werror -Wextra

INCLUDES = "ft_printf.h"

all: $(NAME)

$(NAME):
		@make -C ./libft
		cp libft/libft.a $(NAME)
		@$(CC) -c $(SRCS) $(INCLUDES)
		@ar rcs $(NAME) $(OBJS)
clean:
		@make fclean -C ./libft
		@rm -f *.o

fclean: clean
		@make fclean -C ./libft
		@rm -f $(NAME)

re: fclean all
