#include "ft_printf.h"

int main()
{
	int s;
	int *p;
	t_flags *flags;

	s = 5;
	p = &s;
	//printf("%d\n", printf("%c\n", "abcd"));
	int n_bytes = ft_printf("henlo fren, %c", 'a');
	printf("\n%d\n", n_bytes);
	return (0);
}
