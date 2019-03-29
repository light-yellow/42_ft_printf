/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:14:11 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/29 21:01:14 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_hex(char **str, va_list *ap)
{
	long	value;
	int		counter;
	char	*ptr;

	value = va_arg(*ap, long);
	if (**str == 'x')
		ptr = ft_itoa_base(value, 16, 'a');
	else
		ptr = ft_itoa_base(value, 16, 'A');
	counter = ft_strlen(ptr);
	ft_putstr(ptr);
	free(ptr);
	*str += 1;
	return (counter);
}
