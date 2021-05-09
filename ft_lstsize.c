#include <stdlib.h>
#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*buff;

	if (lst == NULL)
		return(0);
	buff = lst;
	res = 1;            //1 if given list elem
	while (buff -> next)//0 if given ptr to elem
	{                   //or not at all
		buff = buff -> next;
		res++;
	}
	return (res);
}