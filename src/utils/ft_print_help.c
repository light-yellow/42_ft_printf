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

void	ft_putprefix(intmax_t num, char id, t_format *f)
{
	if (num < 0)
		write(1, "-", 1);
	else if (f->plus == 1)
                write(1, "+", 1);
        else if (f->space == 1)
                write(1, " ", 1);
	else if (f->hash)
	{
		if ((num > 0 || f->precision == -1) && (id == 'o' || id == 'O'))
			write(1, "0", 1);
		else if (num > 0 && (id == 'b' || id == 'B'))
			(id == 'b') ? write(1, "0b", 2) : write(1, "0B", 2);
		else if (num > 0 && (id == 'x' || id == 'X'))
			(id == 'x') ? write(1, "0x", 2) : write(1, "0X", 2);
	}
}

void	ft_putzeros(int	nzeros)
{
	while (nzeros > 0)
	{
		write(1, "0", 1);
		nzeros -= 1;
	}
}
