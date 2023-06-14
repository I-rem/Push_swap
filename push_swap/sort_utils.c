#include "push_swap.h"

int is_sorted(t_list *lst)
{
    while (lst->next != NULL)
    {
        if (lst->content > lst->next->content)
            return (0);
        lst = lst->next;
    }

    return (1);
}

void medium_sort(t_list **lst, t_list **lst_b)
{
    int min;
    t_list *temp;

    if (is_sorted(*lst) && *lst_b != NULL)
    {
        push(lst_b, lst, 'a');
        medium_sort(lst, lst_b);
    }
    else if (!is_sorted(*lst))
    {
        temp = *lst;
        min = temp->content;
        while (temp->next != NULL)
        {
            if (temp->next->content < min)
                min = temp->next->content;
            temp = temp->next;
        }
        if ((*lst)->content == min)
            push(lst, lst_b, 'b');
        else if ((*lst)->next->content == min)
            swap(lst, 'a');
        else
            reverse_rotate(lst, 'a');
        medium_sort(lst, lst_b);
    }
}

void little_sort(t_list *lst, t_list **lst_b, int argc, char mode)
{
    if (argc == 3)
        swap(&lst, mode);
    else if (argc == 4)
    {
        if (lst->content > lst->next->content && lst->content > lst->next->next->content)
        {
            if (lst->next->content > lst->next->next->content)
            {
                swap(&lst, mode);
                reverse_rotate(&lst, mode);
            }
            else
                rotate(&lst, mode);
        }
        else if (lst->content < lst->next->content)
        {
            reverse_rotate(&lst, mode);
            if (!is_sorted(lst))
                swap(&lst, mode);
        }
        else
            swap(&lst, mode);
    }
    else if (argc == 5 || argc == 6)
        medium_sort(&lst, lst_b);
}

void big_sort(t_list **lst_a, t_list **lst_b, char mode)
{
    
}


