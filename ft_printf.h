/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:57:32 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/09 18:01:05 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "src/libft/libft.h"

# define LEN_H 1
# define LEN_HH 2
# define LEN_L 3
# define LEN_LL 4

typedef struct	s_flags
{
	int			length;
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precision;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_print_char(char **str, va_list *ap);
int				ft_print_str(char **str, va_list *ap);
int				ft_print_percent(char **str, va_list *ap);
int				ft_print_binary(char **str, va_list *ap);
int				ft_print_integer(char **str, va_list *ap);
int				ft_print_pointer(char **str, va_list *ap);
int				ft_print_hex(char **str, va_list *ap);
int				ft_print_octal(char **str, va_list *ap);
int				ft_print_unsigned(char **str, va_list *ap);
int				ft_print_double(char **str, va_list *ap);
void			ft_init_flags(t_flags *flags);
void			ft_handle_flags(char **str, t_flags *flags);

#endif
