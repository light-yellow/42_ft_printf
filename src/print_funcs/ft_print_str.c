/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:36:05 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/26 16:44:02 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_str(char **str, va_list *ap)
{
	char *ptr;
	int count;

	ptr = va_arg(*ap, char*);
	ft_putstr(va_arg(*ap, char*));
	count = ft_strlen(ptr);
	printf ("count = %d", count);
	*str += count;	
	return (count);
}
