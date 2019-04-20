# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdudley <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 17:59:10 by bdudley           #+#    #+#              #
#    Updated: 2019/04/20 14:49:44 by jgoyette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = ft_printf
NAME = libftprintf.a
FLAGS = #-Wall -Wextra -Werror
SRCS  =  src/ft_printf.c src/ft_handle_format.c src/ft_parse_optionals.c \
	src/utils/ft_cast_nums.c src/utils/ft_num_help.c src/utils/ft_print_help.c \
	src/print_funcs/ft_print_char.c src/print_funcs/ft_print_str.c \
	src/print_funcs/ft_print_pointer.c src/print_funcs/ft_print_percent.c \
	src/print_funcs/ft_print_binary.c src/print_funcs/ft_print_integer.c \
	src/print_funcs/ft_print_hex.c src/print_funcs/ft_print_octal.c \
	src/print_funcs/ft_print_double.c src/print_funcs/ft_print_unsigned.c \
	src/print_funcs/ft_print_non_printable.c
OBJS = $(SRCS:.c=.o)
LIB = ./src/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./src/libft
#	gcc $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
	cp src/libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -I./ft_printf.h -c $< -o $@

clean:
	make -C ./src/libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./src/libft fclean
	rm -f $(NAME)

re: fclean all
