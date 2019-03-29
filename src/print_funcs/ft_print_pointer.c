/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:02:14 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/29 19:34:07 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_pointer(char **str, va_list *ap)
{
	unsigned long	value;
	char			*ptr;

	value = va_arg(*ap, unsigned long);
	ptr = ft_itoa_base(value, 16, 'a');
	ft_putstr("0x");
	ft_putstr(ptr);
	*str += 1;
	return (2 + ft_strlen(ptr));
}
