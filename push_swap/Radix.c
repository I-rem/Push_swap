#include "push_swap.h"
#include <stdio.h>

void    make_positive(t_list **a)
{
    t_list  *temp;

    int min = find_min(*a);
    temp = *a;
    while (temp)
    {
        temp -> content-= min;
        temp = temp -> next;
    }
    
}

/*
void make_positive(t_list **a, int index)
{
    int min = find_min(*a);
    t_list *temp = *a;

    while (temp)
    {
        if (temp->content == min && temp->checked == 0)
        {   
            temp->content = index;
            temp->checked = 1;
            break;
        }
        temp = temp->next;
    }
    temp = *a;
    while (temp)
    {
        if (temp->checked == 0)
        {
            make_positive(a, ++index);
            return ;
        }
        temp = temp->next;
    }
}
*/

void	right_shift(t_list **a)
{
	t_list	*temp;
	
	temp = *a;
	while (*a)
	{
		(*a) -> content = ((*a) -> content >> 1);
		*a = (*a) -> next;
	}
    *a = temp;
}

int	has_lastbit_zero(t_list *a)
{
	t_list	*temp;
	
    temp = a;
	while (temp)
	{
		if ((temp -> content & 1) == 0)
			return (1);
		temp = temp -> next;
	}
	return (0);
}

int all_zero(t_list *a)
{
    t_list  *temp;

    temp = a;
    while (temp)
    {
        if (temp -> content != 0)
            return (0);
        temp = temp -> next;
    }
    return (1);
}

void	radix_sort(t_list **a, t_list **b) // WHY DONT YOU WORK?
{
    //make_positive(a);
   int top;
   t_list   *temp;
   
	while(find_max(*a))
	{
        temp = *a;
        while (temp != NULL && temp -> content % 2 == 0)
            temp = temp -> next;
        if (temp != NULL)
            top = temp -> content;
        else
            top = 0;
        
		while (has_lastbit_zero(*a))
        {
            //TO DO: Stop if a is already sorted
			if (((*a) -> content & 1) == 0)
				push(a, b, 'b');
			else
				rotate(a, 'a');
        }
        //printf("%d ", top);
        if (top != 0){
            while ((*a)->content != top){
                
                rotate(a, 'a');
            }
        }
		while (ft_lstsize(*b) > 0)
			push(b, a, 'a');
        right_shift(a);
	}
}

