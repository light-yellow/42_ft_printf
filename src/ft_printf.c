/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:55:23 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/09 18:11:37 by jgoyette         ###   ########.fr       */
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

int	ft_call_type_print(char **format_id, va_list *ap, t_format *format)
{
	/*if (**format_id == 'c')
		return (ft_print_char(format_id, ap));
	else if (**format_id == 's')
		return (ft_print_str(format_id, ap));
	else*/ if (**format_id == 'p')
		return (ft_print_pointer(format_id, ap, format));
	/*else if (**format_id == '%')
		return (ft_print_percent(format_id, ap));
	else if (**format_id == 'b')
		return (ft_print_binary(format_id, ap));
	else if (**format_id == 'd' || **format_id == 'i')
		return (ft_print_integer(format_id, ap));
	else if (**format_id == 'o')
		return (ft_print_octal(format_id, ap));
	else if (**format_id == 'x' || **format_id == 'X')
		return (ft_print_hex(format_id, ap));
	*/else
		printf("\nhenlo\n");
		//return (ft_no_format_spec(ap));
	return (1);
}

int	ft_print_format(char **str, va_list *ap)
{
	t_format	format;

	*str += 1;
	ft_init_format(&format);
	if (**str)
	{
		ft_handle_optionals(str, &format);
		if (ft_isalpha(**str) || **str == '%')
			return (ft_call_type_print(str, ap, &format));
	}
	return (0);
}

void	ft_putpad(int nspaces)
{
	while (nspaces > 0)
	{
		write(1, " ", 1);
		nspaces -= 1;
	}
}

int	ft_printf(const char *format_string, ...)
{
	va_list	ap;
	int	nbytes;
	char	*str;

	nbytes = 0;
	str = (char *)format_string;
	va_start(ap, format_string);
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
