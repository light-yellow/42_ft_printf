/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:36:05 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/26 16:19:15 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_wstrlen(wchar_t *str)
{
	int	len;

	len = 0;
	while (*str != L'\0')
	{
		len += ft_wcharlen(*str); 
		str += 1;
	}
	return (len);
}

void    ft_print_wstr(char **str, t_format *f)
{
        wchar_t	*ptr;
        int	len;
        int     ptr_len;
        int     padding;
	int	wclen;

	if ((ptr = va_arg(f->ap, wchar_t *)) == NULL)
		ptr = L"(null)";
	ptr_len = ft_wstrlen(ptr);
	len = (f->precision == -1) ? 0 : ptr_len;
    len = (f->precision > 0 && f->precision <= ptr_len) ? f->precision : len;
    padding = ft_maxnum(f->min_width - len, 0);
    ft_putpad(padding, f, f->minus == 0);
	while (*ptr && len > 0)
	{
		wclen = ft_wcharlen(*ptr);
		ft_print_wchar(f, *ptr, wclen);
		ptr += 1;
		len -= wclen;
	}
    ft_putpad(padding, f, f->minus == 1);
    *str += 1;
    f->size += padding;
}


void	ft_print_str(char **str, t_format *f)
{
	char	*ptr;
	int	len;
	int	ptr_len;
	int	padding;

	if (**str == 'S' || f->length == LEN_L)
		ft_print_wstr(str, f);
	else
	{
		if ((ptr = va_arg(f->ap, char *)) == NULL)
			ptr = "(null)";
		ptr_len = ft_strlen(ptr);
		len = (f->precision == -1) ? 0 : ptr_len;
		len = (f->precision > 0 && f->precision <= ptr_len) ? f->precision : len;
		padding = ft_maxnum(f->min_width - len, 0);
		ft_putpad(padding, f, f->minus == 0);
		ft_fill_buffer(f, ptr, len);
		ft_putpad(padding, f, f->minus == 1);
		*str += 1;
		f->size += (len + padding);
	}
}
