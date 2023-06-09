#include "push_swap.h"

void    four_sort(t_list *lst)
{
    return ;
}

void    little_sort(t_list *lst, int argc)
{
    if (argc == 3)
        write (1, "sa\n", 3);
    else if (argc == 4)
    {
        if (lst->content > lst->next->content && lst->content > lst->next->next->content)
                {
                    if (lst->next->content > lst->next->next->content)
                        write(1, "sa\nrra\n",7); 
                    else
                        write (1, "ra\n", 4);
                }
        else if ((lst->content) < (lst->next->content))
        {
            write (1, "rra\n", 4);
            if (lst->content < lst->next->next->content)
                write (1, "sa\n", 3);
        }
        else
            write (1, "sa\n", 3);
    }
    else if (argc == 5)
        four_sort(lst);
}

