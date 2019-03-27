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

#include "stdio.h"

char	*ft_itoa_base(int value, int base, char letter_case)
{
	int		sign;
	unsigned int	num;
	char		*result;
	int		len;

	sign = 0;
	if (value < 0)
	{
		if (base == 10)
			sign = 1;
		num = -value;
	}
	else
		num = value;
	len = ft_numlen(num, base) + sign;
	printf("len = %d\n", len);
	if (result = ft_strnew((size_t)len))
	{
		while (len >= 0)
		{
			result[len - 1] = ft_getchar(num % base, letter_case);
			num /= base;
			len -= 1;
		}
		if (sign)
			result[0] = '-';
	}
	printf("result: |%s|\n", result);
	return (result);
}

int main(void)
{
	ft_itoa_base(15, 16, 'a');
	return (0);
}
