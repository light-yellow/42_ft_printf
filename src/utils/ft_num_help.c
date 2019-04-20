/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:12:45 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/20 19:12:48 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_update_optionals(char id, t_format *format)
{
	if (format->precision != 0)
		format->zero = 0;
	if (id == 'O' || id == 'U' || id == 'D' || id == 'B')
		format->length = LEN_L;
}
