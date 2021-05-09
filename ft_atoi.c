#include "libft.h"

static char	*check_ex(const char *num, int *sign)
{
	while (*num == ' ' || (*num >= 9 && *num <= 13))
		num++;
	if (*num == '-')
	{
		*sign = 1;
		num++;
	}
	else
	{
		*sign = 0;
		if (*num == '+')
			num++;
	}
	return ((char *)num);
}

int	ft_atoi(const char *num)
{
	unsigned long long	res;
	int					buff;
	int					sign;
	unsigned long long	max;

	max = 9223372036854775807;
	res = 0;
	num = check_ex(num, &sign);
	while (*num)
	{
		if (*num > 57 || *num < 48)
			break ;
		buff = *num - '0';
		res = res * 10 + buff;
		num++;
	}
	if (res > max && sign == 0)
		return (-1);
	if (res > max + 1 && sign == 1)
		return (0);
	if (sign)
		return (-res);
	return (res);
}
