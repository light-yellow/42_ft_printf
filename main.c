#include "ft_printf.h"

int main()
{
	//printf("%d\n", printf("%c\n", "abcd"));
	int n_bytes = ft_printf("Katya puk!\n%cVilena puk!%c%s", '@', '*', "KEK");
	printf("\n%d\n", n_bytes);
	return (0);
}
