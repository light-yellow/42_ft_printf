#include "../ft_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->length = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->precision = 0;
}

void	ft_handle_flags(char **str, t_flags *flags)
{
	printf("\nздесь я обработаю флаги");
}
