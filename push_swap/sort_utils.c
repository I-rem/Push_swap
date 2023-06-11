#include "push_swap.h"
int find_min(t_list *lst)
{
    int min = lst->content;
    lst = lst->next;

    while (lst != NULL)
    {
        if (lst->content < min)
            min = lst->content;
        lst = lst->next;
    }

    return min;
}

int find_max(t_list *lst)
{
    int max = lst->content;
    lst = lst->next;

    while (lst != NULL)
    {
        if (lst->content > max)
            max = lst->content;
        lst = lst->next;
    }

    return max;
}
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

int get_pivot(t_list *lst, int size)
{
    int count = 0;
    int sum = 0;

    while (lst && count < size)
    {
        sum += lst->content;
        lst = lst->next;
        count++;
    }

    return sum / size;
}


void big_sort(t_list **lst_a, t_list **lst_b)
{
    int size = ft_lstsize(*lst_a);

    if (is_sorted(*lst_a))
        return;

    if (size <= 3)
    {
        if (size == 2 && (*lst_a)->content > (*lst_a)->next->content)
            swap(lst_a, 'a');
        else if (size == 3)
            little_sort(*lst_a, lst_b, 3);
        return;
    }

    int pivot = get_pivot(*lst_a, size);
    int count = 0;

    while (count < size)
    {
        if ((*lst_a)->content < pivot)
        {
            push(lst_a, lst_b, 'b');
            count++;
        }
        else
        {
            rotate(lst_a, 'a');
            count++;
        }
    }

    big_sort(lst_a, lst_b);
    //big_sort(lst_b, lst_a);

    while (ft_lstsize(*lst_b) != 1)
        push(lst_b, lst_a, 'a');
}











