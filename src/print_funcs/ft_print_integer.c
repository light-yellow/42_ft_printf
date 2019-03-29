/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:53:01 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/29 17:53:04 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_integer(char **str, va_list *ap)
{
	long value;
	char *ptr;

	value = va_arg(*ap, int);
	ptr = ft_itoa_base(value, 10, 'a');
	ft_putstr(ptr);
	*str += 1;
	return (ft_strlen(ptr));
}
