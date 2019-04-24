/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:55:23 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/24 17:59:36 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_until_percent(char **str, t_format *f)
{
	char	*ptr;
	int		str_len;

	ptr = ft_strchr(*str, '%');
	if (ptr == NULL)
	{
		ft_fill_buffer(f, *str, ft_strlen(*str));
		str_len = ft_strlen(*str);
	}
	else
	{
		ft_fill_buffer(f, *str, ptr - *str);
		str_len = ptr - *str;
	}
	*str = ptr;
	f->size += str_len;
}

void	ft_call_type_print(char **str, va_list *ap, t_format *format)
{
	if (**str == 'c' || **str == 'C')
		ft_print_char(str, ap, format);
	else if (**str == 's' || **str == 'S')
		ft_print_str(str, ap, format);
	else if (**str == 'p')
		ft_print_pointer(str, ap, format);
	else if (**str == 'r')
		ft_print_non_printable(str, ap, format);
	else if (**str == 'f')
		ft_print_double(str, ap, format);
	else if (**str == 'b' || **str == 'B')
		ft_print_binary(str, ap, format);
	else if (**str == 'd' || **str == 'D' || **str == 'i')
		ft_print_integer(str, ap, format);
	else if (**str == 'o' || **str == 'O')
		ft_print_octal(str, ap, format);
	else if (**str == 'x' || **str == 'X')
		ft_print_hex(str, ap, format);
	else if (**str == 'u' || **str == 'U')
		ft_print_unsigned(str, ap, format);
	else
		ft_no_format_spec(str, ap, format);
}

void	ft_print_format(char **str, va_list *ap, t_format *format)
{

	*str += 1;
	if (**str)
	{
		ft_handle_optionals(str, format);
		if (ft_isalpha(**str) || **str == '%')
			ft_call_type_print(str, ap, format);
	}
}

int	ft_printf(const char *format_string, ...)
{
	va_list	ap;
	char	*str;
	t_format    format;

	format.buffer = "";
	format.size = 0;
	format.printed = 0;
	str = (char *)format_string;
	va_start(ap, format_string);
	if (str == NULL)
		return (-1);
	while (str != NULL)
	{
		ft_init_format(&format);
		if (*str == '%')
			ft_print_format(&str, &ap, &format);
		else
			ft_print_until_percent(&str, &format);
	}
	//printf("|buff: [%s], size: [%d]|", format.buffer, format.size);
	write(1, format.buffer, format.size);
	if (ft_strlen(format.buffer) != 0)
		free(format.buffer);
	va_end(ap);
	return (format.size + format.printed);
}
