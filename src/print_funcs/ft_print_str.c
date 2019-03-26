/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:36:05 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/26 16:53:18 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_str(char **str, va_list *ap)
{
	char *ptr;

	ptr = va_arg(*ap, char*);
	ft_putstr(ptr);
	*str += 1;	
	return (ft_strlen(ptr));
}
