# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 12:56:26 by mviinika          #+#    #+#              #
#    Updated: 2022/03/24 11:23:29 by mviinika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
	formats.c length.c \
	flags.c treat_with_modifiers.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = clang

FLAGS = -Wall -Werror -Wextra -c -g

INCLUDES = "ft_printf.h"

all: $(NAME)

$(NAME):
		@$(CC) $(FLAGS) $(SRCS) $(INCLUDES)
		@ar rcs $(NAME) $(OBJS)
clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
