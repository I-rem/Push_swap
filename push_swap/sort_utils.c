#include "push_swap.h"
int is_sorted(t_list *lst)
{

    while (lst -> next != NULL)
    {
        if (lst -> content < lst -> next -> content)
            lst = lst -> next;
        else
            return (0);
    }
    return (1);
}

void    medium_sort(t_list **lst, t_list **lst_b)
{
    int min;
    t_list  *temp;

    //char num = (*lst) -> content + '0';
    //write(1, &num, 1);
    if (is_sorted(*lst) && ft_lstsize(*lst_b) != 1)
    {
        push(lst_b, lst, 'a');
        medium_sort(lst, lst_b); 
    }
    else if (!is_sorted(*lst))
    {
        temp = *lst;
        min = temp -> content;
        while (temp -> next != NULL)
        {
            if (temp -> next -> content < min)
                min = temp -> next -> content;
            temp = temp -> next;
        }
        if ((*lst) -> content == min)
            push(lst, lst_b, 'b');
        else if ((*lst) -> next -> content == min)
            swap(lst, 'a');
        else
            reverse_rotate(lst, 'a');
        medium_sort(lst, lst_b); 
    }
}

void    little_sort(t_list *lst, t_list **lst_b, int argc)
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
    else if (argc == 5 || argc == 6)
        medium_sort(&lst, lst_b);
}

