/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:53:13 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/14 09:32:23 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_percent(char **str, t_format *format)
{
	int padding;

        padding = ft_maxnum(format->min_width - 1, 0);
        ft_putpad(padding, format, format->minus == 0);
	ft_putchar('%');
	ft_putpad(padding, format, format->minus == 1);
	*str += 1;
	return (1 + padding);
}
