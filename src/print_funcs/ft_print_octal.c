/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:14:23 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/20 19:51:20 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static	int	ft_calc_len(t_format *f, intmax_t num, int numlen)
{
	int len;

	if (f->precision == -1 && num == 0)
		len = 0;
	else if (f->precision > numlen)
		len = f->precision;
	else
		len = numlen;
	if (f->hash && (num > 0 || f->precision == -1) && numlen >= f->precision)
		len += 1;
	if (f->zero && f->min_width > len)
		len = f->min_width;
	return (len);
}

int			ft_print_octal(char **str, va_list *ap, t_format *format)
{
	uintmax_t	value;
	char		*ptr;
	int			ptr_len;
	int			len;
	int			padding;

	ft_update_optionals(**str, format);
	value = ft_cast_uint(ap, format);
	ptr = ft_ulltoa_base(value, 8, 'a');
	ptr_len = (value != 0 || format->precision != -1) ? ft_strlen(ptr) : 0;
	len = ft_calc_len(format, value, ptr_len);
	padding = ft_maxnum(format->min_width - len, 0);
	ft_putpad(padding, format, format->minus == 0);
	ft_putprefix(value, **str, format);
	ft_putzeros(len - ptr_len - ((format->hash &&
			(value > 0 || format->precision == -1)) ? 1 : 0));
	write(1, ptr, ptr_len);
	ft_putpad(padding, format, format->minus == 1);
	*str += 1;
	free(ptr);
	return (len + padding);
}
