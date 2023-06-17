#include "push_swap.h"

void	make_positive(t_list **a)
{
	int 	min;
	t_list	*temp;
	
	min = find_min(*a);
    temp = *a;
    
    while (temp)
    {
        temp->content -= min;
        temp = temp->next;
    }
}

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

void	radix_sort(t_list **a, t_list **b)
{
	// Make every num in list >= 0
    //make_positive(a);
	// is sorted check? Or we can stop when every num is 0
   // int num;
	while(!all_zero(*a))
	{
        /*num = (*a) -> content + '0';
        write(1, &num, 1); 
        write(1," ",1);*/
		// Push b if num % 2 == 0
		while (has_lastbit_zero(*a))
        {
            //TO DO: Stop if a is already sorted
			if (((*a) -> content & 1) == 0)
				push(a, b, 'b');
			else
				rotate(a, 'a');
        }
		// Push back a
		while (ft_lstsize(*b) > 0)
			push(b, a, 'a');
		// Right Shift
        right_shift(a);
	}
}

