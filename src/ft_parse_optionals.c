/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:38:35 by jgoyette          #+#    #+#             */
/*   Updated: 2019/04/09 18:23:37 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

	if (**str == '.')
	{
		*str += 1;
		if ((precision = ft_atoi(*str)) > 0)
		{
			format->precision = precision;
			*str += ft_numlen((unsigned int)precision, (unsigned int)10);
		}
	}
}

void	ft_parse_length(char **str, t_format *format)
{
	if (**str == 'h')
	{
		format->length = (*(*str + 1) == 'h') ? LEN_HH : LEN_H;
		*str += (*(*str + 1) == 'h') ? 2 : 1;
	}
	else if (**str == 'l')
	{
		format->length = (*(*str + 1) == 'l') ? LEN_LL : LEN_L;
		*str += (*(*str + 1) == 'h') ? 2 : 1;
	}
	else if (**str == 'j')
	{
		//add code
	}
	else if (**str == 'z')
	{
		//add code
	}
}
