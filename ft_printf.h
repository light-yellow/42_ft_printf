/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:57:32 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/26 17:21:10 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int	length;
	int	hash;
	int	zero;
	int	minus;
	int	plus;
	int	width;
	int	precision;
}		t_flags;

int		ft_printf(const char *format, ...);
int		ft_print_char(char **str, va_list *ap);
int		ft_print_str(char **str, va_list *ap);
int		ft_print_pointer(char **str, va_list *ap);
char		*ft_itoa_base(uintmax_t num, uintmax_t base, char c);
void    	ft_init_flags(t_flags *flags);
void    	ft_handle_flags(char *str, t_flags *flags);

#endif
