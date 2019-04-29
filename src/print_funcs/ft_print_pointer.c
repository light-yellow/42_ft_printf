/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:02:14 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/26 16:29:40 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_calc_len(t_format *format, uintmax_t num, int num_len)
{
	int	len;

	if (format->precision == -1 && num == 0)
		len = 0;
	else if (format->precision > num_len)
		len = format->precision;
	else
		len = num_len;
	if (format->zero && format->min_width > len)
		len = format->min_width;
	else
		len += 2;
	return (len);
}

void	ft_print_pointer(char **str, t_format *format)
{
	uintmax_t		value;
	char			*ptr;
	int				ptr_len;
	int				len;
	int				padding;

	ft_update_optionals(**str, format);
	value = va_arg(format->ap, unsigned long);
	ptr = ft_ulltoa_base(value, 16, 'a');
	ptr_len = (format->precision != -1) ? ft_strlen(ptr) : 0;
	len = ft_calc_len(format, value, ptr_len);
	padding = ft_maxnum(format->min_width - len, 0);
	ft_putpad(padding, format, format->minus == 0);
	ft_fill_buffer(format, "0x", 2);
	ft_putzeros(format, len - ptr_len - 2);
	ft_fill_buffer(format, ptr, ptr_len);
	ft_putpad(padding, format, format->minus == 1);
	*str += 1;
	free(ptr);
}
