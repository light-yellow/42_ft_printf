#include "../../ft_printf.h"

void    ft_putpad(int nchars, t_format *format, int pad_needed)
{
        char    *c;

	if (pad_needed)
	{
        	c = (format->zero == 1 && format->minus == 0) ? "0" : " ";
        	while (nchars > 0)
        	{
                	write(1, c, 1);
                	nchars -= 1;
        	}
	}
}

void	ft_putprefix(intmax_t num, t_format *format)
{
	if (num < 0)
		write(1, "-", 1);
	else if (format->plus == 1)
                write(1, "+", 1);
        else if (format->space == 1)
                write(1, " ", 1);
}

void	ft_putzeros(int	nzeros)
{
	while (nzeros > 0)
	{
		write(1, "0", 1);
		nzeros -= 1;
	}
}
