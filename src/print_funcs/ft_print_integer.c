/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:53:01 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/29 21:02:14 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_integer(char **str, va_list *ap)
{
	long value;
	int		counter;
	char *ptr;

	value = va_arg(*ap, int);
	ptr = ft_itoa_base(value, 10, 'a');
	counter = ft_strlen(ptr);
	ft_putstr(ptr);
	free(ptr);
	*str += 1;
	return (counter);
}
