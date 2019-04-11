#include "ft_printf.h"

int main()
{
	int s;
	int *p;

	s = 5;
	p = &s;
	int nbytes = ft_printf("HEWWO! %.5d", 14);
	printf("\nchars printed: %d\n", nbytes);
	//printf(" %.2.2f %f\n", 65.67876, 6.4567);
	//int n_bytes = ft_printf("henlo fren, |%%|  %x, %X, %d, %i, %o ====\n", 15, 15, 123, -123, 7);
	//printf("\n%d\n", n_bytes);
	//printf("\n octal = %s\n", ft_itoa_base(7, 8, 'a'));
	return (0);
}
