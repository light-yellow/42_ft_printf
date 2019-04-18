/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_noprintable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:54:45 by bdudley           #+#    #+#             */
/*   Updated: 2019/04/17 17:54:48 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"
#define BASE "0123456789abcdef"

static int ft_print_code(int c)
{
    if (c >= 16)
        return (ft_print_code(c / 16) + 1);
    ft_putchar(BASE [c % 16]);
    return (1);
}

int	ft_print_non_printable(char **str, va_list *ap)
{
    char *ptr;
    int padding;

    padding++;
    ptr = va_arg(*ap, char*);
    while (*ptr != '\0')
    {
        if (!(ft_isprint(*ptr)))
        {
            ft_putchar('\\');
            if (*ptr < 16) {
                padding++;
                ft_putchar('0');
            }
            padding +=  ft_print_code(*ptr);
        }
        else
            ft_putchar(*ptr);
        ptr++;
        padding++;
    }
    *str += 1;
    return (1);
}