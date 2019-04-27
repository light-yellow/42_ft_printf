/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:14:05 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/26 14:45:51 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_fill_buffer(t_format *f, char *str, int size)
{
	if (BUFF_SIZE - f->buffer_size < size)
	{
		write(1, f->buffer, f->buffer_size);
		write(1, str, size);
		f->printed += f->buffer_size + size;
		f->size = 0;
		f->buffer_size = 0;
	}
	else
	{
		ft_memcpy(&(f->buffer[f->buffer_size]), str, size);
		f->buffer_size += size;
		f->size += size;
	}
}

void	ft_putpad(int nchars, t_format *f, int pad_needed)
{
	char	*c;

	if (pad_needed)
	{
		c = (f->zero == 1 && f->minus == 0) ? "0" : " ";
		while (nchars > 0)
		{
			ft_fill_buffer(f, c, 1);
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

void	ft_no_format_spec(char **str, t_format *f)
{
	int padding;

	padding = ft_maxnum(f->min_width - 1, 0);
	ft_putpad(padding, f, f->minus == 0);
	ft_fill_buffer(f, *str, 1);
	ft_putpad(padding, f, f->minus == 1);
	*str += 1;
}
