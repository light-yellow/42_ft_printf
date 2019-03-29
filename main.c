#include "ft_printf.h"

int main()
{
	int s;
	int *p;
	t_flags *flags;

	s = 5;
	p = &s;
	//printf("%d\n", printf("%c\n", "abcd"));
	int n_bytes = ft_printf("henlo fren, %x, %X, %d, %i, %o", 15, 15, 123, -123, 8);
	printf("\n%d\n", n_bytes);
	return (0);
}
