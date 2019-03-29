/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:14:23 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/29 20:55:54 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_octal(char **str, va_list *ap)
{
	unsigned int	value;
	int				counter;
	char			*ptr;

	value = va_arg(*ap, unsigned int);
	ptr = ft_itoa_base(value, 8, 'a');
	counter = ft_strlen(ptr);
	ft_putstr(ptr);
	free(ptr);
	*str += 1;
	return (counter);
}
