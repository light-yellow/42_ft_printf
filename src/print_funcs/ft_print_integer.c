/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:53:01 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/29 21:02:14 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_integer(char **str, va_list *ap, t_format *format)
{
	intmax_t	value;
	char		*ptr;
	int		ptr_len;
	int		len;
	int		padding;

	value = ft_cast_int(ap, format);
	(format->precision != 0) ? format->zero = 0: 0;
	ptr = ft_ulltoa_base((value < 0) ? -value : value, 10, 'a');
	ptr_len = (value != 0 || format->precision != -1) ? ft_strlen(ptr) : 0;
	len = (format->precision == -1 && value == 0) ? 0 : ptr_len;
	len = (format->precision > ptr_len) ? format->precision : len;
	if ((value >= 0 && (format->plus || format->space)) || value < 0)
		len += 1;
	padding = ft_maxnum(format->min_width - len, 0);
	ft_putpad(padding, format, format->minus == 0);
	ft_putprefix(value, format);
	ft_putzeros(format->precision - ptr_len);
	write(1, ptr, ptr_len);
	ft_putpad(padding, format, format->minus == 1);
	*str += 1;
	free(ptr);
	return (len + padding);
}
