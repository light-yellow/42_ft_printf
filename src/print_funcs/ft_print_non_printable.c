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

static void ft_print_code(int c)
{

}

int	ft_print_double(char **str, va_list *ap)
{
    char *ptr;
    int padding;

    padding++:
    ptr = va_arg(*ap, char*);
    while (*ptr != '\0')
    {
        if (!(ft_isprint(ptr)))
        {
            ft_putchar('\\');
            if (*ptr < 16) {
                padding++;
                ft_putchar('0');
            }
            ft_print_code(*ptr);
        }
        else
            ft_putchar(*ptr);
        ptr++;
        padding++;
    }
    *str += 1;
    return (1);
}