/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:57:32 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/26 16:08:37 by jgoyette         ###   ########.fr       */
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

typedef struct		s_format
{
	unsigned int	hash : 1;
	unsigned int	zero : 1;
	unsigned int 	minus : 1;
	unsigned int	plus : 1;
	unsigned int	space : 1;
	int				length;
	int				min_width;
	int				precision;
	int				size;
	int				printed;
	char			*buffer;
	va_list			ap;
}					t_format;

int					ft_printf(const char *format, ...);
void				ft_fill_buffer(t_format *f, char *str, int size);
int					ft_printf(const char *format, ...);
void				ft_putpad(int nchars, t_format *f, int pad_needed);
void				ft_putprefix(uintmax_t num, char id, t_format *f);
void				ft_putsign(intmax_t num, t_format *f);
void				ft_putzeros(t_format *f, int nzeros);
void				ft_print_char(char **str, t_format *f);
void				ft_print_str(char **str, t_format *f);
void				ft_print_non_printable(char **str, t_format *f);
void				ft_print_binary(char **str,  t_format *f);
void				ft_print_integer(char **str, t_format *f);
void				ft_print_pointer(char **str, t_format *f);
void				ft_print_hex(char **str, t_format *f);
void				ft_print_octal(char **str, t_format *f);
void				ft_print_unsigned(char **str, t_format *f);
void				ft_print_double(char **str, t_format *f);
void				ft_no_format_spec(char **str, t_format *f);
void				ft_init_format(t_format *f);
void				ft_handle_optionals(char **str, t_format *f);
void				ft_parse_flags(char **str, t_format *f);
void				ft_parse_width(char **str, t_format *f);
void				ft_parse_precision(char **str, t_format *f);
void				ft_parse_length(char **str, t_format *f);
void				ft_update_optionals(char format_id, t_format *f);
intmax_t			ft_cast_int( t_format *f);
uintmax_t			ft_cast_uint(t_format *f);
void				ft_print_wchar(t_format *f, int c, int len);
int					ft_wcharlen(int c);

#endif
