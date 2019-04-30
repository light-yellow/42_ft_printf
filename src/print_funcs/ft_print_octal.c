/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:14:23 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/30 13:03:19 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static	int	ft_calc_len(t_format *f, uintmax_t num, int numlen)
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

void	ft_print_octal(char **str, t_format *f)
{
	uintmax_t	value;
	char		*ptr;
	int			ptr_len;
	int			len;
	int			padding;

	ft_update_optionals(**str, f);
	value = ft_cast_uint(f);
	ptr = ft_ulltoa_base(value, 8, 'a');
	ptr_len = (value > 0 || f->precision != -1) ? ft_strlen(ptr) : 0;
	len = ft_calc_len(f, value, ptr_len);
	padding = ft_maxnum(f->min_width - len, 0);
	ft_putpad(padding, f, f->minus == 0);
	ft_putprefix(value, **str, f);
	ft_putzeros(f, ft_maxnum(len - ptr_len - ((f->hash &&
			(value > 0 || f->precision == -1)) ? 1 : 0), 0));
	ft_fill_buffer(f, ptr, ptr_len);
	ft_putpad(padding, f, f->minus == 1);
	*str += 1;
	free(ptr);
}
