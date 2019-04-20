#include "../../ft_printf.h"

void	ft_update_optionals(char id, t_format *format)
{
	if (format->precision != 0)
                format->zero = 0;
        if (id == 'O' || id == 'U' || id == 'D' || id == 'B')
                format->length = LEN_L;
}
