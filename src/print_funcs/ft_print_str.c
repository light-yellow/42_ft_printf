/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:36:05 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/14 09:27:21 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_str(char **str, va_list *ap, t_format *format)
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
									format->precision : ptr_len;
	padding = ft_maxnum(format->min_width - len, 0);
	if (padding > 0 && format->minus == 0)
		ft_putpad(padding, format);
	write(1, ptr, len);
	if (padding > 0 && format->minus == 1)
		ft_putpad(padding, format);
	*str += 1;
	return (len + padding);
}
