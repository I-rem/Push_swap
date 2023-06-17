#include "push_swap.h"

void	make_positive(t_list **a)
{
	int 	min;
	t_list	*temp;
	
	min = find_mind(*a);
    temp = *a;
    
    while (temp)
    {
        temp->content -= min_val;
        temp = temp->next;
    }
}

void	right_shift(t_list **a)
{
	t_list	*temp;
	
	temp = *a;
	wihle (temp)
	{
		temp -> content >> 1;
		temp = temp -> next;
	}
}

int	has_lastbit_zero(t_list **a)
{
	t_list	*temp;
	
	while (temp)
	{
		if (temp -> content % 2 == 0)
			return (1);
		temp = temp -> next;
	}
	return (0);
}

void	radix_sort(t_list **a, t_list **b)
{
	// Make every num in list >= 0
	// is sorted check? Or we can stop when every num is 0
	while(!is_sorted(*a))
	{
		// Push b if num % 2 == 0
		while (has_lastbit_zero(a))
			if ((*a) -> content % 2 == 0 && !is_sorted(*a))
				push(a, b, 'b');
			else if (!is_sorted(*a))
				rotate(a, 'a');
		// Push back a
		while (ft_lstsize(*b) > 0)
			push(b, a, 'a');
		// Right Shift a
		right_shift(a);
	}
}
