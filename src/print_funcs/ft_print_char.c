/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:26:23 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/26 16:19:50 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_putbuff(t_format *f, int padding)
{
	write(1, f->buffer, ft_strlen(f->buffer));
    write(1, "\0", 1);
    if ((*f->buffer))
		free(f->buffer);
    f->buffer = "";
	f->printed += (f->size + 1);
	f->size = 0;
	if (f->minus)
	{
		f->printed -= padding;
		f->size += padding;
	}
}

int	ft_wcharlen(int c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else
		return (4);

}

void	ft_print_wchar(t_format *f, int c, int len)
{
	char wc[4];

	if (c <= 0x7F || len == 1)
		wc[0] = (char)c;
	else if (c <= 0x7FF)
	{
		wc[0] = (char)((c >> 6) | 0xC0);
		wc[1] = (char)((c & 0x3F) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		wc[0] = (char)((c >> 12) | 0xE0);
		wc[1] = (char)(((c >> 6) & 0x3F) | 0x80);
		wc[2] = (char)((c & 0x3F) | 0x80);
	}
	else
	{
		wc[0] = (char)((c >> 18) | 0xF0);
		wc[1] = (char)(((c >> 12) & 0x3F) | 0x80);
		wc[2] = (char)(((c >> 6) & 0x3F) | 0x80);
		wc[3] = (char)((c & 0x3F) | 0x80);
	}
	ft_fill_buffer(f, wc, len);
	f->size += len;
}

void	ft_print_char(char **str, t_format *f)
{
	int padding;
	int c;
	int	len;

	c = va_arg(f->ap, int);
	len = (**str == 'C' || f->length == LEN_L) ? ft_wcharlen(c): 1;
	padding = ft_maxnum(f->min_width - len, 0);
	ft_putpad(padding, f, f->minus == 0);
	f->size += padding;
	if (c != '\0')
		ft_print_wchar(f, c, len);
	else
		ft_putbuff(f, padding);
	ft_putpad(padding, f, f->minus == 1);
	*str += 1;
}
