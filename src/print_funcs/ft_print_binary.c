/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:52:18 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/29 17:55:41 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_binary(char **str, va_list *ap)
{
	long value;
	char *ptr;

	value = va_arg(*ap, long);
	ptr = ft_itoa_base(value, 2, 'a');
	ft_putstr(ptr);
	*str += 1;
	return (ft_strlen(ptr));
}
