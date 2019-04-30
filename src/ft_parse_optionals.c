/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:38:35 by jgoyette          #+#    #+#             */
/*   Updated: 2019/04/14 09:37:34 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_parse_flags(char **str, t_format *format)
{
	while (**str)
	{
		if (**str == '#')
			format->hash = 1;
		else if (**str == '0')
			format->zero = 1;
		else if (**str == '-')
			format->minus = 1;
		else if (**str == '+')
			format->plus = 1;
		else if (**str == ' ')
			format->space = 1;
		else
			break ;
		*str += 1;
	}
	if (format->minus)
		format->zero = 0;
	if (format->plus)
		format->space = 0;
}

void	ft_parse_width(char **str, t_format *format)
{
	int width;

	if ((width = ft_atoi(*str)) > 0)
	{
		format->min_width = width;
		*str += ft_numlen((unsigned int)width, (unsigned int)10);
	}
}

void	ft_parse_precision(char **str, t_format *format)
{
	int precision;

	while (**str == '.')
	{
		*str += 1;
		if ((precision = ft_atoi(*str)) > 0)
		{
			format->precision = precision;
			*str += ft_numlen((unsigned int)precision, (unsigned int)10);
		}
		else
		{
			format->precision = -1;
			while (ft_isdigit(**str))
				*str += 1;
		}
	}
}

void	ft_put_length(char **str, t_format *f, unsigned int length_type, int size)
{
	f->length = length_type;
	*str += size;
}

void	ft_parse_length(char **str, t_format *f)
{
	while (**str)
	{
		if (**str == 'h' && *(*str + 1) == 'h')
			ft_put_length(str, f, LEN_HH, 2);
		else if (**str == 'h')
			ft_put_length(str, f, LEN_H, 1);
		else if (**str == 'l' && *(*str + 1) == 'l')
			ft_put_length(str, f, LEN_LL, 2);
		else if (**str == 'l')
			ft_put_length(str, f, LEN_L, 1);
		else if (**str == 'j')
			ft_put_length(str, f, LEN_J, 1);
		else if (**str == 'z')
			ft_put_length(str, f, LEN_Z, 1);
		else if (**str == 'L')
			ft_put_length(str, f, LEN_LD, 1);
		else
			break ;
	}
}
