#include "ft_printf.h"

int main()
{
	int s;
	int *p;

	s = 5;
	p = &s;
	//printf("%d\n", printf("%c\n", "abcd"));
	int n_bytes = ft_printf("%p", p);
	printf("\n%d\n", n_bytes);
	return (0);
}
