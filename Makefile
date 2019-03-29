# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdudley <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 17:59:10 by bdudley           #+#    #+#              #
#    Updated: 2019/03/29 18:43:10 by jgoyette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
FLAGS = #-Wall -Wextra -Werror
SRCS  =  main.c src/ft_printf.c src/ft_handle_flags.c src/print_funcs/ft_print_char.c src/print_funcs/ft_print_str.c src/print_funcs/ft_print_pointer.c src/print_funcs/ft_print_percent.c src/print_funcs/ft_print_binary.c src/print_funcs/ft_print_integer.c src/print_funcs/ft_print_hex.c src/print_funcs/ft_print_octal.c
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
