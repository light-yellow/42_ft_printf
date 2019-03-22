/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:55:23 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/22 14:04:02 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_until_percent(const char **format)
{
	char *ptr;

	ptr = ft_strchr(*format, '%');
	if (ptr == NULL)
		ft_putstr(*format);
	else 
		write(1, *format, ptr - *format);
	*format = ptr;
}

int	ft_printf(const char* format, ...)
{
	va_list ap_1;
	char *ptr;
	va_start(ap_1, format);
	if (format == NULL)
		return (-1);
	while (format != NULL)
	{
		if (*format == '%')
		{
			printf("GG\n");
			format += 2;
		}
		else 
			ft_print_until_percent(&format);
	}
	va_end(ap_1);
	return (0);
}
