/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:53:01 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/24 18:00:02 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*ft_put_double(double value)
{
	char	*str;
	char	*integer;
	char	*fractional;
	int		counter;

	integer = ft_itoa_base((int)value, 10, 'a');
	fractional = ft_strnew(7);
	value = value > 0 ? value : -value;
	value -= (int)value;
	fractional[0] = '.';
	counter = 1;
	while (counter < 7)
	{
		if (counter == 6 && ((int)(value * 100) % 10) > 4)
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

void			ft_print_double(char **str, va_list *ap, t_format *format)
{
	double	value;
	int		counter;
	char	*ptr;

	value = va_arg(*ap, double);
	ptr = ft_put_double(value);
	counter = ft_strlen(ptr);
	ft_putstr(ptr);
	free(ptr);
	*str += 1;
	format->size = counter;
}
