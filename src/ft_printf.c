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
	int	str_len;

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

void	ft_call_type_print(char **str, va_list *ap, t_format *f)
{
	if (**str == 'c' || **str == 'C')
		ft_print_char(str, ap, f);
	else if (**str == 's' || **str == 'S')
		ft_print_str(str, ap, f);
	else if (**str == 'p')
		ft_print_pointer(str, ap, f);
	else if (**str == 'r')
		ft_print_non_printable(str, ap, f);
	else if (**str == 'f')
		ft_print_double(str, ap, f);
	else if (**str == 'b' || **str == 'B')
		ft_print_binary(str, ap, f);
	else if (**str == 'd' || **str == 'D' || **str == 'i')
		ft_print_integer(str, ap, f);
	else if (**str == 'o' || **str == 'O')
		ft_print_octal(str, ap, f);
	else if (**str == 'x' || **str == 'X')
		ft_print_hex(str, ap, f);
	else if (**str == 'u' || **str == 'U')
		ft_print_unsigned(str, ap, f);
	else
		ft_no_format_spec(str, f);
}

void	ft_print_format(char **str, va_list *ap, t_format *f)
{
	*str += 1;
	if (**str)
	{
		ft_handle_optionals(str, f);
		if (ft_isalpha(**str) || **str == '%')
			ft_call_type_print(str, ap, f);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	t_format    f;

	f.buffer = "";
	f.size = 0;
	f.printed = 0;
	str = (char *)format;
	va_start(ap, format);
	if (str == NULL)
		return (-1);
	while (str != NULL)
	{
		ft_init_format(&f);
		if (*str == '%')
			ft_print_format(&str, &ap, &f);
		else
			ft_print_until_percent(&str, &f);
	}
	write(1, f.buffer, f.size);
	if (ft_strlen(f.buffer) != 0)
		free(f.buffer);
	va_end(ap);
	return (f.size + f.printed);
}
