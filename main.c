#include <stdio.h>
#include <stdlib.h>
#include "libft.h"


void thru_list(t_list *begin)
{
	while(begin)
	{
		printf("%s\n", (char *)(begin->content));
		begin = begin -> next;
	}
}

int main (void)
{
    char *str1 = "string";
    char *str2 = "strong";
    char *str3 = "strung";
    t_list obj1;
    t_list obj2;
    t_list *obj0 = ft_lstnew(str3);
    t_list *ptr0 = &obj1;

    
    obj1.content = str1;
    obj1.next = &obj2;
    obj2.content = str2;
    obj2.next = NULL;
    ft_lstadd_front(&ptr0, obj0);
    ft_lstadd_front(&ptr0, ft_lstnew("strang"));
    thru_list(ptr0);
    printf("\n%s\n", (ft_lstlast(ptr0)) -> content);
    free (obj0);
    return (0);
}