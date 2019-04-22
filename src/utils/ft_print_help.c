/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:14:05 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/20 19:17:03 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_putpad(int nchars, t_format *format, int pad_needed)
{
	char	*c;

	if (pad_needed)
	{
		c = (format->zero == 1 && format->minus == 0) ? "0" : " ";
		while (nchars > 0)
		{
			write(1, c, 1);
			nchars -= 1;
		}
	}
}

void	ft_putprefix(uintmax_t num, char id, t_format *f)
{
	if (f->hash)
	{
		if ((num > 0 || f->precision == -1) && (id == 'o' || id == 'O'))
			write(1, "0", 1);
		else if (num > 0 && (id == 'b' || id == 'B'))
			(id == 'b') ? write(1, "0b", 2) : write(1, "0B", 2);
		else if (num > 0 && (id == 'x' || id == 'X'))
			(id == 'x') ? write(1, "0x", 2) : write(1, "0X", 2);
	}
}

void	ft_putsign(intmax_t num, t_format *f)
{
	if (num < 0)
		write(1, "-", 1);
	else if (f->plus == 1)
		write(1, "+", 1);
	else if (f->space == 1)
		write(1, " ", 1);
}

void	ft_putzeros(int nzeros)
{
	while (nzeros > 0)
	{
		write(1, "0", 1);
		nzeros -= 1;
	}
}

int	ft_no_format_spec(char **str, va_list *ap)
{
	write(1, *str, 1);
	*str += 1;
	return (1);
}
