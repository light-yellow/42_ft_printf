/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:36:05 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/24 17:55:53 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_print_str(char **str, va_list *ap, t_format *format)
{
	char	*ptr;
	int		len;
	int		ptr_len;
	int		padding;

	if ((ptr = va_arg(*ap, char *)) == NULL)
		ptr = "(null)";
	ptr_len = ft_strlen(ptr);
	len = (format->precision == -1) ? 0 : ptr_len;
	len = (format->precision > 0 && format->precision <= ptr_len) ?
									format->precision : len;
	padding = ft_maxnum(format->min_width - len, 0);
	ft_putpad(padding, format, format->minus == 0);
	ft_fill_buffer(format, ptr, len);
	ft_putpad(padding, format, format->minus == 1);
	*str += 1;
	format->size = len + padding;
}
