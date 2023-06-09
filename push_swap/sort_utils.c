#include "push_swap.h"

void    little_sort(t_list *lst, int argc)
{
    if (argc == 3)
        write (1, "sa\n", 3);
    else if (argc == 4)
    {
        if ((lst->content) < (lst->next->content))
        {
            write (1, "rra\n", 4);
            if (lst->next->content > lst->next->next->content)
                write (1, "sa\n", 3);
        }
        else if ((lst->content > lst->next->content) && (lst->next->content < lst->next->next->content))
                {
                    if (lst->content < lst->next->next->content)
                        write(1, "sa\n",3); 
                    else
                        write (1, "ra\n", 3);
                }
        else
            write (1, "sa\n", 3);
    }
}

