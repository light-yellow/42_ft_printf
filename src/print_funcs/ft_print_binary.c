/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:52:18 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/29 21:01:20 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_binary(char **str, va_list *ap)
{
	long	value;
	int		counter;
	char	*ptr;

	value = va_arg(*ap, long);
	ptr = ft_itoa_base(value, 2, 'a');
	counter = ft_strlen(ptr);
	ft_putstr(ptr);
	free(ptr);
	*str += 1;
	return (counter);
}
