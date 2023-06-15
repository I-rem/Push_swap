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

int find_min(t_list *lst)
{
    int min = lst->content;
    while (lst != NULL)
    {
        if (lst->content < min)
            min = lst->content;
        lst = lst->next;
    }
    return (min);
}

int find_max(t_list *lst)
{
    int max = lst->content;
    while (lst != NULL)
    {
        if (lst->content > max)
            max = lst->content;
        lst = lst->next;
    }
    return (max);
}
int find_pos(t_list *lst, int num)
{
    int pos = 0;
    while (lst != NULL)
    {
        if (lst->content == num)
            return (pos);
        lst = lst->next;
        pos++;
    }
    return (-1);
}

void medium_sort(t_list **lst, t_list **lst_b)
{
    int min;

    if (is_sorted(*lst) && *lst_b != NULL)
    {
        push(lst_b, lst, 'a');
        medium_sort(lst, lst_b);
    }
    if (!is_sorted(*lst))
    {   
        if (ft_lstsize(*lst) == 3)
            little_sort(lst, 3, 'a');
        min = find_min(*lst);
        if ((*lst)->content == min)
            push(lst, lst_b, 'b');
        else if ((*lst)->next->content == min)
            swap(lst, 'a');
        else if(find_pos(*lst, min) > ft_lstsize(*lst) / 2)
            reverse_rotate(lst, 'a');
        else
            rotate(lst, 'a');
        medium_sort(lst, lst_b);
    }
}
/*
void big_sort (t_list **lst, t_list **lst_b)
{

}
*/
void little_sort(t_list **lst, int argc, char mode)
{
    if (argc == 2)
        swap(lst, mode);
    else if (argc == 3)
    {
        if ((*lst)->content > (*lst)->next->content && (*lst)->content > (*lst)->next->next->content)
        {
            if ((*lst)->next->content > (*lst)->next->next->content)
            {
                swap(lst, mode);
                reverse_rotate(lst, mode);
            }
            else
                rotate(lst, mode);
        }
        else if ((*lst)->content < (*lst)->next->content)
        {
            reverse_rotate(lst, mode);
            if (!is_sorted(*lst))
                swap(lst, mode);
        }
        else
            swap(lst, mode);
    }   
}

