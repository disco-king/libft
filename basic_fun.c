#include <stdio.h>
#include "libft.h"
//for succesfull compilation use
//current setup and following:
//gcc basic_fun.c -L. -lft

int main (void)
{
	char *line1 = ft_strdup("first line");
	char *line2 = ft_strdup("second line");
	t_list *start = ft_lstnew(line2);
	ft_lstadd_front(&start, ft_lstnew(line1));
	t_list *lst = start;
	printf("printing list of size %d\n", ft_lstsize(lst));
	while(lst)
	{
		printf("lst content <%s>\n", (char *)lst->content);
		lst = lst->next;
	}
	return (0);
}
