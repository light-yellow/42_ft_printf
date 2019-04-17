/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:26:23 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/14 09:31:59 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_char(char **str, va_list *ap, t_format *format)
{
	int padding;

	padding = ft_maxnum(format->min_width - 1, 0);
	ft_putpad(padding, format, format->minus == 0);
	ft_putchar(va_arg(*ap, int));
	ft_putpad(padding, format, format->minus == 1);
	*str += 1;
	return (1 + padding);
}
