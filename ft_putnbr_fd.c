#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l;
	char	buff;

	l = n;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l *= -1;
	}
	if (l >= 10)
	{
		buff = l % 10 + 48;
		ft_putnbr_fd(l / 10, fd);
		ft_putchar_fd(buff, fd);
	}
	else if (l < 10)
	{
		buff = l + 48;
		ft_putchar_fd(buff, fd);
	}
}
