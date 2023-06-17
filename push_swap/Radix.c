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

void	right_shift(t_list **a)
{
	 t_list *temp = *a;

    while (temp)
    {
        temp->content = (temp->content >> 1);
        temp = temp->next;
    }
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
    make_positive(a); //TO DO:  maybe find a different way to do this
   t_list   *temp;
   
	while(find_max(*a))
	{
        temp = *a;
        while (temp != NULL && temp -> content % 2 == 0)
            temp = temp -> next;
        if (temp != NULL)
            temp -> checked = 1;
		while (has_lastbit_zero(*a))
        {
            //TO DO: Stop if a is already sorted
			if (((*a) -> content & 1) == 0)
				push(a, b, 'b');
			else
				rotate(a, 'a');
        }
        if (temp != NULL){
            while ((*a)->checked != 1)  
                rotate(a, 'a');
        (*a)->checked = 0;}
		while (ft_lstsize(*b) > 0)
			push(b, a, 'a');
        right_shift(a);
	}
}

