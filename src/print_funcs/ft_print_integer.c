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

static int	ft_calc_len(t_format *format, intmax_t num, int num_len)
{
	int len;

	if (format->precision == -1 && num == 0)
		len = 0;
	else if (format->precision > num_len)
		len = format->precision;
	else
		len = num_len;
        if ((num >= 0 && (format->plus || format->space)) || num < 0)
		len += 1;
	return (len);
}

int	ft_print_integer(char **str, va_list *ap, t_format *format)
{
	intmax_t	value;
	char		*ptr;
	int		ptr_len;
	int		len;
	int		padding;

	ft_update_optionals(**str, format);
	value = ft_cast_int(ap, format);
	ptr = ft_ulltoa_base((value < 0) ? -value : value, 10, 'a');
	ptr_len = (value != 0 || format->precision != -1) ? ft_strlen(ptr) : 0;
	len = ft_calc_len(format, value, ptr_len);
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
