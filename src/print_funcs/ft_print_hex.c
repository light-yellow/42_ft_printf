/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:14:11 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/29 18:16:24 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_hex(char **str, va_list *ap)
{
	long value;
	char *ptr;

	value = va_arg(*ap, long);
	if (*str == 'x')
		ptr = ft_itoa_base(value, 16, 'a');
	else
		ptr = ft_itoa_base(value, 16, 'A');
	ft_putstr(ptr);
	*str += 1;
	return (ft_strlen(ptr));
}
