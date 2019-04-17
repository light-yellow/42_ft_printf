#include "../../ft_printf.h"

intmax_t        ft_cast_int(va_list *ap, t_format *format)
{
        intmax_t        result;

        if (format->length == LEN_H)
                result = (intmax_t)((short)va_arg(*ap, int));
        else if (format->length == LEN_HH)
                result = (intmax_t)((char)va_arg(*ap, int));
        else if (format->length == LEN_L)
                result = (intmax_t)va_arg(*ap, long);
        else if (format->length == LEN_LL)
                result = (intmax_t)va_arg(*ap, long long);
        else if (format->length == LEN_J)
                result = va_arg(*ap, intmax_t);
        else if (format->length == LEN_Z)
                result = (intmax_t)va_arg(*ap, size_t);
        else
                result = (intmax_t)va_arg(*ap, int);
        return (result);
}

uintmax_t        ft_cast_uint(va_list *ap, t_format *format)
{
        uintmax_t        result;

        if (format->length == LEN_H)
                result = (uintmax_t)((unsigned short)va_arg(*ap, int));
        else if (format->length == LEN_HH)
                result = (uintmax_t)((unsigned char)va_arg(*ap, int));
        else if (format->length == LEN_L)
                result = (uintmax_t)va_arg(*ap, unsigned long);
        else if (format->length == LEN_LL)
                result = (uintmax_t)va_arg(*ap, unsigned long long);
        else if (format->length == LEN_J)
                result = va_arg(*ap, uintmax_t);
        else if (format->length == LEN_Z)
                result = (uintmax_t)va_arg(*ap, size_t);
        else
                result = (uintmax_t)va_arg(*ap, unsigned int);
        return (result);
}
