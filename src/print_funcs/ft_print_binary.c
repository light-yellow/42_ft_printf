/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:52:18 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/26 16:53:42 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_calc_len(t_format *format, uintmax_t num, int num_len)
{
	int	len;

	if (format->precision == -1 && num == 0)
		len = 0;
	else if (format->precision > num_len)
		len = format->precision;
	else
		len = num_len;
	if (format->hash && num != 0)
		len += 2;
	if (format->zero && format->min_width > len)
		len = format->min_width;
	return (len);
}

void			ft_print_binary(char **str, t_format *f)
{
	uintmax_t	value;
	char		*ptr;
	int			ptr_len;
	int			len;
	int			padding;

	ft_update_optionals(**str, f);
	value = ft_cast_uint(f);
	ptr = ft_ulltoa_base(value, 2, 'a');
	ptr_len = (value != 0 || f->precision != -1) ? ft_strlen(ptr) : 0;
	len = ft_calc_len(f, value, ptr_len);
	padding = ft_maxnum(f->min_width - len, 0);
	ft_putpad(padding, f, f->minus == 0);
	ft_putprefix(value, **str, f);
	ft_putzeros(f, len - ptr_len - ((f->hash && value != 0) ? 2 : 0));
	write(1, ptr, ptr_len);
	ft_putpad(padding, f, f->minus == 1);
	*str += 1;
	free(ptr);
}
