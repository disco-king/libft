#include <stdio.h>
#include <stdlib.h>


typedef struct  s_list
{
void *content;
struct s_list *next;
}               t_list;

t_list *ft_lstnew(void *content);
int ft_lstsize(t_list *lst);
void ft_lstadd_front(t_list **lst, t_list *new);

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
    printf("%d\n", ft_lstsize(ptr0));
    free (obj0);
    return (0);
}