#include "libft.h"

int	ft_numlen(unsigned int num, int base)
{
	int	len;

	len = 1;
	while (num >= base)
	{
		num /= base;
		len += 1;
	}
	return (len);
}

char	ft_getchar(int num, char letter_case)
{
	if (num < 10)
		return (num + '0');
	else
		return (num - 10 + letter_case);
}

char	*ft_itoa_base(int value, int base, char letter_case)
{
	int		sign;
	unsigned int	num;
	char		*result;
	int		len;

	sign = (value < 0 && base == 10) ? 1 : 0;
	num = (value < 0) ? -value : value;
	len = ft_numlen(num, base) + sign;
	if (result = ft_strnew((size_t)len))
	{
		while (len > 0)
		{
			result[len - 1] = ft_getchar(num % base, letter_case);
			num /= base;
			len -= 1;
		}
		if (sign)
			result[0] = '-';
	}
	return (result);
}