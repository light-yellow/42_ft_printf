/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:53:01 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/30 12:52:00 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static	int	ft_calc_len(t_format *format, intmax_t num, int num_len)
{
	int len;

	if (format->precision == -1 && num == 0)
		len = 0;
	else if (format->precision > num_len)
		len = format->precision;
	else
		len = num_len;
	if (format->plus || format->space || num < 0)
		len += 1;
	return (len);
}

void			ft_print_integer(char **str, t_format *format)
{
	intmax_t	value;
	char		*ptr;
	int			ptr_len;
	int			len;
	int			padding;

	ft_update_optionals(**str, format);
	value = ft_cast_int(format);
	if ((format->plus || format->space || value < 0) && format->zero)
		format->precision -= (format->precision > 0) ? 1 : 0;
	ptr = ft_ulltoa_base((value < 0) ? -value : value, 10, 'a');
	ptr_len = (value != 0 || format->precision != -1) ? ft_strlen(ptr) : 0;
	len = ft_calc_len(format, value, ptr_len);
	padding = ft_maxnum(format->min_width - len, 0);
	ft_putpad(padding, format, format->minus == 0);
	ft_putsign(value, format);
	ft_putzeros(format, format->precision - ptr_len);
	ft_fill_buffer(format, ptr, ptr_len);
	ft_putpad(padding, format, format->minus == 1);
	*str += 1;
	free(ptr);
}
