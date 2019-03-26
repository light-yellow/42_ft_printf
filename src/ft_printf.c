/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:55:23 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/26 17:21:17 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_until_percent(char **str)
{
	char	*ptr;
	int	str_len;

	ptr = ft_strchr(*str, '%');
	if (ptr == NULL)
	{
		ft_putstr(*str);
		str_len = ft_strlen(*str);
	}
	else
	{
		write(1, *str, ptr - *str);
		str_len = ptr - *str;
	}
	*str = ptr;
	return (str_len);
}

int	ft_call_type_print(char **format_spec, va_list *ap)
{
	if (**format_spec == 'c')
		return (ft_print_char(format_spec, ap));
	else if (**format_spec == 's')
		return (ft_print_str(format_spec, ap));
	else if (**format_spec == 'p')
		return (ft_print_pointer(format_spec, ap));
	else
		printf("\nhenlo\n");
		//return (ft_no_format_spec(ap));
	return (1);
}

int	ft_print_format(char **str, va_list *ap)
{
	*str += 1;
	if (**str)
	{
		//тут нужно обработать флаги
		if (ft_isalpha(**str) || **str == '%')
			return (ft_call_type_print(str, ap));
	}
	return (0);
}

int	ft_printf(const char* format, ...)
{
	va_list	ap;
//	char	*ptr;
	int	nbytes;
	char	*str;

	nbytes = 0;
	str = (char *)format;
	va_start(ap, format);
	if (str == NULL)
		return (-1);
	while (str != NULL)
	{
		if (*str == '%')
			nbytes += ft_print_format(&str, &ap);
		else 
			nbytes += ft_print_until_percent(&str);
	}
	va_end(ap);
	return (nbytes);
}
