/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:02:14 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/20 19:52:34 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_pointer(char **str, va_list *ap, t_format *format)
{
	unsigned long	value;
	char			*ptr;
	int				ptr_len;
	int				padding;

	value = va_arg(*ap, unsigned long);
	ptr = ft_ulltoa_base(value, 16, 'a');
	ptr_len = ft_strlen(ptr) + 2;
	padding = ft_maxnum(format->min_width - ptr_len, 0);
	ft_putpad(padding, format, format->minus == 0);
	ft_putprefix(value, **str, format);
	ft_putstr(ptr);
	ft_putpad(padding, format, format->minus == 1);
	*str += 1;
	free(ptr);
	return (ptr_len + padding);
}
