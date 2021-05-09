#include <stdio.h>

//for succesfull compilation use
//current setup and following:
//gcc basic_fun.c -L. -lft

int ft_atoi(char *);

int main (void)
{
	char *i = "1234";
	printf("%d\n", ft_atoi(i));
	return (0);
}