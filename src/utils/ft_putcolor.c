#include "../../inc/ft_printf.h"

void	ft_putcolor(char **str, t_format *f)
{
	int len;
	int put_len;

	if (ft_strncmp(*str, "{eoc}", (len = 5)) == 0)
		ft_fill_buffer(f, COLOR_EOC, (put_len = 4));
	else if (ft_strncmp(*str, "{red}", (len = 5)) == 0)
		ft_fill_buffer(f, COLOR_RED, (put_len = 5));
	else if (ft_strncmp(*str, "{green}", (len = 7)) == 0)
                ft_fill_buffer(f, COLOR_GREEN, (put_len = 5));
	else if (ft_strncmp(*str, "{yellow}", (len = 8)) == 0)
                ft_fill_buffer(f, COLOR_YELLOW, (put_len = 5));
	else if (ft_strncmp(*str, "{blue}", (len = 6)) == 0)
                ft_fill_buffer(f, COLOR_BLUE, (put_len = 5));
	else if (ft_strncmp(*str, "{magenta}", (len = 9)) == 0)
                ft_fill_buffer(f, COLOR_MAGENTA, (put_len = 5));
	else if (ft_strncmp(*str, "{cyan}", (len = 6)) == 0)
                ft_fill_buffer(f, COLOR_CYAN, (put_len = 5));
	else
	{
		ft_no_format_spec(str, f);
		return ;
	}
	*str += len;
	f->printed -= put_len;
}
