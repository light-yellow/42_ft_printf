#include "inc/ft_printf.h"
#include "stdio.h"
#include <limits.h>
#include <locale.h>
#include <stdlib.h>
void	ft_42printf(const char *str, ...)
{
	va_list ap;
	long double value;

	va_start(ap, str);
	value = va_arg(ap, long double);
	printf("%Lf", value);
	va_end(ap);
}

int main()
{

//	setlocale(LC_ALL, "en_US.UTF-8");
//	setlocale(LC_ALL, "");
	int nbytes9 = ft_printf("%*.*d", 0, 3, 0);
	printf("\n");
	int nbytes10 = printf("%*.*d", 0, 3, 0);
	printf("\nnbytes9: %d, nbytes10: %d\n", nbytes9, nbytes10);
}
