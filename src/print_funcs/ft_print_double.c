/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:53:01 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/26 16:27:50 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static char	*ft_put_double(long double value, t_format *f)
{
	char	*str;
	char	*integer;
	char	*fractional;
	int		counter;

	integer = ft_itoa_base(value, 10, 'a'); //ch delat
//	counter = ft_strlen(integer) + (value > 0) ? counter : counter + 1;
//    counter = ((f->precision + counter) > f->min_width) ? f->precision + counter : f->min_width;
	fractional = ft_strnew(f->precision + 1);
	value = value > 0 ? value : -value;
	value -= (int)value;
	fractional[0] = '.';
	counter = 1;
	while (counter <= f->precision)
	{
		if (counter == f->precision && ((int)(value * 100) % 10) > 4)
			value += 0.1;
		fractional[counter] = (int)(value * 10) + '0';
		value = value * 10 - (int)(value * 10);
		counter++;
	}
	str = ft_strnew(ft_strlen(integer) + ft_strlen(fractional));
	ft_strcpy(str, integer);
	ft_strcpy(str + ft_strlen(integer), fractional);
	free(integer);
	free(fractional);
	return (str);
}

void			ft_print_double(char **str, t_format *f)
{
	long double	value;
	int		counter;
	char	*ptr;
	char    *s;

	f->precision = (f->precision == 0) ? 6 :f->precision;
	if (f->length == 7)
	    value = va_arg(f->ap, long double);
	else
        value = va_arg(f->ap, double);
	ptr = ft_put_double(value, f);
    counter = ft_strlen(ptr);
	if (f->precision == 6 && f->min_width != 0)
    {
	    s = ft_strnew(f->min_width - counter);
	    s = (char *)ft_memset((void *)s, ' ', f->min_width - counter);
        counter += ft_strlen(s);
        ft_putbuffer(f, s, counter);
	    free(s);
    }
    ft_putbuffer(f, ptr, counter);
	*str += 1;
	f->printed += counter;
}
