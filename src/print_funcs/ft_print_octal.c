/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:14:23 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/29 20:55:54 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_octal(char **str, va_list *ap, t_format *format)
{
	uintmax_t        value;
        char            *ptr;
        int             ptr_len;
        int             len;
        int             padding;

        value = ft_cast_int(ap, format);
        if (format->precision != 0)
                format->zero = 0;
        ptr = ft_ulltoa_base(value, 8, 'a');
        ptr_len = ft_strlen(ptr);
        len = (format->precision == -1) ? 0 : ptr_len;
        len = (format->precision > 0 && format->precision <= ptr_len) ?
                                        format->precision : ptr_len;
        len += (value >= 0 && (format->plus == 1|| format->space == 1)) ? 1 : 0;
        padding = ft_maxnum(format->min_width - len, 0);
        if (format->plus == 1)
                write(1, "+", 1);
        else if (format->space == 1)
                write(1, " ", 1);
        ft_putpad(padding, format, format->minus == 0);
        write(1, ptr, len);
        ft_putpad(padding, format, format->minus == 1);
        *str += 1;
        free(ptr);
        return (len + padding);

}
