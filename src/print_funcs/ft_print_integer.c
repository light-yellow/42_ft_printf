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

intmax_t	ft_cast_int(va_list *ap, t_format *format)
{
	intmax_t	result;

	if (format->length == LEN_H)
		result = (intmax_t)((short)va_arg(*ap, int));
	else if (format->length == LEN_HH)
		result = (intmax_t)((char)va_arg(*ap, int));
	else if (format->length == LEN_L)
		result = (intmax_t)va_arg(*ap, long);
	else if (format->length == LEN_LL)
		result = (intmax_t)va_arg(*ap, long long);
	else if (format->length == LEN_J)
		result = va_arg(*ap, intmax_t);
	else if (format->length == LEN_Z)
		result = (intmax_t)va_arg(*ap, size_t);
	else
		result = (intmax_t)va_arg(*ap, int);
	return (result);
}

int	ft_print_integer(char **str, va_list *ap, t_format *format)
{
	intmax_t	value;
	char		*ptr;
	int		ptr_len;
	int		len;
	int		padding;

	value = ft_cast_int(ap, format);
	if (format->precision != 0)
		format->zero = 0;
	ptr = ft_lltoa_base(value, 10, 'a');
	ptr_len = ft_strlen(ptr);
	len = (format->precision == -1) ? 0 : ptr_len;
	len = (format->precision > 0 && format->precision <= ptr_len) ?
					format->precision : ptr_len;
	len += (value >= 0 && (format->plus == 1|| format->space == 1)) ? 1 : 0;
	padding = ft_maxnum(format->min_width - len, 0);
	if (format->plus == 1)
		write(1, "+", 1);
	else if (format->space == 1)
		write(1, " ", 1);
	if (padding > 0 && format->minus == 0)
		ft_putpad(padding, format);
	write(1, ptr, len);
	if (padding > 0 && format->minus == 1)
		ft_putpad(padding, format);
	*str += 1;
	free(ptr);
	return (len + padding);
}
