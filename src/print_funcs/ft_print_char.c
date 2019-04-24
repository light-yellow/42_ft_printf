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

void	ft_putbuff(t_format *f, int padding)
{
	write(1, f->buffer, ft_strlen(f->buffer));
        write(1, "\0", 1);
        if (ft_strlen(f->buffer) != 0)
	        free(f->buffer);
        f->buffer = "";
	f->printed = f->size + 1 + padding;
}

void	ft_print_char(char **str, va_list *ap, t_format *f)
{
	int padding;
	int c;

	padding = ft_maxnum(f->min_width - 1, 0);
	ft_putpad(padding, f, f->minus == 0);
	c = va_arg(*ap, int);
	(c == '\0') ? ft_putbuff(f, padding) : ft_fill_buffer(f, (char *)&c, 1);
	ft_putpad(padding, f, f->minus == 1);
	*str += 1;
	f->size = (c == '\0') ? 0 : 1 + padding;
}
