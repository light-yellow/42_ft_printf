# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdudley <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 17:59:10 by bdudley           #+#    #+#              #
#    Updated: 2019/03/22 14:21:53 by bdudley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
FLAGS = -Wall -Wextra -Werror
SRCS  = main.c ft_printf.c
OBJS = $(SRCS:.c=.o)
LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	gcc $(FLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c ./ft_printf.h
	gcc $(FLAGS) -c $< -o $@

clean:
	make -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all