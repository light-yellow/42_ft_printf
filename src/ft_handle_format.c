#include "../ft_printf.h"

void    ft_init_format(t_format *format)
{
        format->length = 0;
        format->hash = 0;
        format->zero = 0;
        format->minus = 0;
        format->plus = 0;
        format->space = 0;
        format->min_width = 0;
        format->precision = 0;
}

void    ft_handle_optionals(char **str, t_format *format)
{
        ft_parse_flags(str, format);
        ft_parse_width(str, format);
        ft_parse_precision(str, format);
        ft_parse_length(str, format);
}

