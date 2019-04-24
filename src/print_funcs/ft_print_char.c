/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:26:23 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/24 18:03:38 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_print_char(char **str, va_list *ap, t_format *format)
{
	int padding;
	int c;

	padding = ft_maxnum(format->min_width - 1, 0);
	ft_putpad(padding, format, format->minus == 0);
	c = va_arg(*ap, int);
	ft_fill_buffer(format, (char *)&c, 1);
	ft_putpad(padding, format, format->minus == 1);
	*str += 1;
	if (c == '\0')
		format->size = 0;
	else
		format->size = 1 + padding;
}
