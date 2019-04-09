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

void	ft_init_flags(t_flags *flags)
{
	flags->length = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = 0;
}

int		ft_parse_flags(char **str, t_flags *flags)
{
	if (**str == '#')
		flags->hash = 1;
	else if (**str == '0')
		flags->zero = 1;
	else if (**str == '-')
		flags->minus = 1;
	else if (**str == '+')
		flags->plus = 1;
	else if (**str == ' ')
		flags->space = 1;
	else
		return (0);
	*str += 1;
	return (1);
}

int	ft_parse_width(char **str, t_flags *flags)
{
	int	width;
	if ((width = ft_atoi(*str)) > 0)
	{
		flags->width = width;
		*str += ft_numlen((unsigned int)width, (unsigned int)10); 
		return (1);
	}
	return (0);
}

int	ft_parse_precision(char **str, t_flags *flags)
{
	int	precision;

	if (**str == '.')
	{
		*str += 1;
		if ((precision = ft_atoi(*str)) > 0)
		{
			flags->precision = precision;
			*str += ft_numlen((unsigned int)precision, (unsigned int)10);
		}
		return (1);
	}
	return (0);
}

int	ft_parse_length(char **str, t_flags *flags)
{
	if (**str == 'h')
	{
		flags->length = (*(*str + 1) == 'h') ? LEN_HH : LEN_H;
		*str += (*(*str + 1) == 'h') ? 2 : 1;
	}
	else if (**str == 'l')
	{
		flags->length = (*(*str + 1) == 'l') ? LEN_LL : LEN_L;
		*str += (*(*str + 1) == 'h') ? 2 : 1;
	}
	else
		return (0);
	return (1);
}

void	ft_handle_flags(char **str, t_flags *flags)
{
	int found_flags = 0;
	while (ft_parse_length(str, flags) || ft_parse_flags(str, flags) ||
			ft_parse_width(str, flags) || ft_parse_precision(str, flags))
		found_flags += 1;
}
