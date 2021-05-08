typedef struct  s_list
{
void *content;
struct s_list *next;
}               t_list;

int ft_lstsize(t_list *lst)
{
    int res;
    t_list *buff;

    buff = lst;
    res = 1;            //1 if given list elem
    while (buff -> next)//0 if given ptr to elem
    {                   //or not at all
        buff = buff -> next;
        res++;
    }
    return (res);
}