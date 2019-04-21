#include "ft_printf.h"
#include "stdio.h"
#include <limits.h>

int main()
{
//	int s;
//	int *p;

//	s = 554634;
//	p = &s;
//	int nbytes1 = printf("printf    - pointer: |%20p|\n", (void *)p);
//	int nbytes2 = ft_printf("ft_printf - pointer: |%20p|\n", (void *)p);
//	printf("\nnbytes1: %d, nbytes2: %d\n", nbytes1, nbytes2);
	
	//int nbytes3 = ft_printf("char: |%c|\n", 68);
	//int nbytes4 = printf("char: |%c|\n", 68);
	//printf("\nnbytes3: %d, nbytes4: %d\n", nbytes3, nbytes4);
	
//	int nbytes5 = ft_printf("char: |%s|\n", "=^__^=");
//      int nbytes6 = printf("char: |%%|\n");
//      printf("\nnbytes5: %d, nbytes6: %d\n", nbytes5, nbytes6);


//      int nbytes7 = ft_printf("ft_printf - d: |%+010d|\n", 3);
//      int nbytes8 = printf("printf    - d: |%+010d|\n", 3);
//      printf("\nnbytes7: %d, nbytes8: %d\n", nbytes7, nbytes8);
//
	int nbytes9 = ft_printf("%4.s", "42");
	printf("\n");
	int nbytes10 = printf("%4.s", "42");
	printf("\nnbytes9: %d, nbytes10: %d\n", nbytes9, nbytes10);



//  	printf("%f\n", 5.040404040404404004004040404040400040404040404040404040404040040404040404045);
//  	ft_printf("%f\n", 5.040404040404404004004040404040400040404040404040404040404040040404040404045);
      	//printf(" %.2.2f %f\n", 65.67876, 6.4567);
	//int n_bytes = ft_printf("henlo fren, |%%|  %x, %X, %d, %i, %o ====\n", 15, 15, 123, -123, 7);
	//printf("\n%d\n", n_bytes);
	//printf("\n octal = %s\n", ft_it	return (0);
}
