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

	ft_printf("%Lf", 1 /3);
//	setlocale(LC_ALL, "en_US.UTF-8");
//setlocale(LC_ALL, "");
//	int nbytes9 = ft_printf("|%S|", L"(╯°□°)╯︵ ┻━┻ ");
//	printf("\n");
//	int nbytes10 = printf("|%S|", L"(╯°□°)╯︵ ┻━┻ ");
//	printf("\nnbytes9: %d, nbytes10: %d\n", nbytes9, nbytes10);
}
