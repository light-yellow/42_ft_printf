#include "ft_printf.h"

int main()
{
	int s;
	int *p;

	s = 554634;
	p = &s;
	//int nbytes1 = printf("pointer: |%-10p|\n", (void *)p);
	//int nbytes2 = ft_printf("pointer: |%-10p|\n", (void *)p);
	//printf("\nnbytes1: %d, nbytes2: %d\n", nbytes1, nbytes2);
	
	//int nbytes3 = ft_printf("char: |%-c|\n", 68);
	//int nbytes4 = printf("char: |%-c|\n", 68);
	//printf("\nnbytes3: %d, nbytes4: %d\n", nbytes3, nbytes4);
	
	int nbytes5 = ft_printf("char: |%s|\n", "puk!");
        int nbytes6 = printf("char: |%-10.2s|\n", "puk!");
        printf("\nnbytes5: %d, nbytes6: %d\n", nbytes5, nbytes6);

	//printf(" %.2.2f %f\n", 65.67876, 6.4567);
	//int n_bytes = ft_printf("henlo fren, |%%|  %x, %X, %d, %i, %o ====\n", 15, 15, 123, -123, 7);
	//printf("\n%d\n", n_bytes);
	//printf("\n octal = %s\n", ft_itoa_base(7, 8, 'a'));
	return (0);
}
