/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:14:05 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/24 15:27:59 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_fill_buffer(t_format *f, char *str, int size)
{
	char *new_buffer;
	char *s2;

	s2 = ft_strnew(size);
	s2 = ft_strncpy(s2, str, size);
	new_buffer = ft_strjoin(f->buffer, s2);
	if (ft_strlen(f->buffer) != 0)
		free(f->buffer);
	free(s2);
	f->buffer = new_buffer;
}

void	ft_putpad(int nchars, t_format *format, int pad_needed)
{
	char	*c;

	if (pad_needed)
	{
		c = (format->zero == 1 && format->minus == 0) ? "0" : " ";
		while (nchars > 0)
		{
			ft_fill_buffer(format, c, 1);
			nchars -= 1;
		}
	}
}

void	ft_putprefix(uintmax_t num, char id, t_format *f)
{
	if (f->hash)
	{
		if ((num > 0 || f->precision == -1) && (id == 'o' || id == 'O'))
			ft_fill_buffer(f, "0", 1);
		else if (num > 0 && (id == 'b' || id == 'B'))
			(id == 'b') ? ft_fill_buffer(f, "0b", 2) : ft_fill_buffer(f, "0B", 2);
		else if (num > 0 && (id == 'x' || id == 'X'))
			(id == 'x') ? ft_fill_buffer(f, "0x", 2) : ft_fill_buffer(f, "0X", 2);
	}
}

void	ft_putsign(intmax_t num, t_format *f)
{
	if (num < 0)
		ft_fill_buffer(f, "-", 1);
	else if (f->plus == 1)
		ft_fill_buffer(f, "+", 1);
	else if (f->space == 1)
		ft_fill_buffer(f, " ", 1);
}

void	ft_putzeros(t_format *f, int nzeros)
{
	while (nzeros > 0)
	{
		ft_fill_buffer(f, "0", 1);
		nzeros -= 1;
	}
}

int	ft_no_format_spec(char **str, va_list *ap, t_format *format)
{
	int padding;

	padding = ft_maxnum(format->min_width - 1, 0);
	ft_putpad(padding, format, format->minus == 0);
	ft_fill_buffer(format, *str, 1);
	ft_putpad(padding, format, format->minus == 1);
	*str += 1;
	return (1 + padding);
}
