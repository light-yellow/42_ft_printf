/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:57:32 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/14 09:37:02 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "src/libft/libft.h"

# define LEN_H	1
# define LEN_HH	2
# define LEN_L	3
# define LEN_LL	4
# define LEN_J	5
# define LEN_Z	6

typedef struct	s_format
{
    int	length;
    int	hash;
    int	zero;
    int	minus;
    int	plus;
    int	space;
    int	min_width;
    int	precision;
}		t_format;

int		ft_printf(const char *format_string, ...);
void		ft_putpad(int nchars, t_format *format, int pad_needed);
void		ft_putprefix(intmax_t num, t_format *format);
void		ft_putzeros(int nzeros);
int		ft_print_char(char **str, va_list *ap, t_format *format);
int		ft_print_str(char **str, va_list *ap, t_format *format);
int		ft_print_non_printable(char **str, va_list *ap);
int		ft_print_percent(char **str, va_list *ap);
int		ft_print_binary(char **str, va_list *ap);
int		ft_print_integer(char **str, va_list *ap, t_format *format);
int		ft_print_pointer(char **str, va_list *ap, t_format *format);
int		ft_print_hex(char **str, va_list *ap, t_format *format);
int		ft_print_octal(char **str, va_list *ap, t_format *format);
int		ft_print_unsigned(char **str, va_list *ap, t_format *format);
int		ft_print_double(char **str, va_list *ap);
void		ft_init_format(t_format *format);
void		ft_handle_optionals(char **str, t_format *format);
void		ft_parse_flags(char **str, t_format *format);
void		ft_parse_width(char **str, t_format *format);
void		ft_parse_precision(char **str, t_format *format);
void		ft_parse_length(char **str, t_format *format);
void		ft_update_optionals(char format_id, t_format *format);
intmax_t	ft_cast_int(va_list *ap, t_format *format);
uintmax_t	ft_cast_uint(va_list *ap, t_format *format);


#endif
