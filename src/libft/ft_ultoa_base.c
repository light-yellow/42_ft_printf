#include "libft.h"

static	char	ft_getchar(int num, char letter_case)
{
	if (num < 10)
		return (num + '0');
	else
		return (num - 10 + letter_case);
}

char	*ft_ultoa_base(unsigned long long num, unsigned long long base, char letter_case)
{
	char	*result;
	int		len;

	len = ft_numlen(num, base);
	if ((result = ft_strnew((size_t)len)))
	{
		while (len > 0)
		{
			result[len - 1] = ft_getchar(num % base, letter_case);
			num /= base;
			len -= 1;
		}
	}
	return (result);
}
