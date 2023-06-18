#include "push_swap.h"

void    make_positive(t_list **a)
{
    t_list  *temp;
    int		min;
	
	min = find_min(*a);
    temp = *a;
    while (temp)
    {
        temp -> content-= min;
        temp = temp -> next;
    }
    
}

void	right_shift(t_list **a)
{
	 t_list *temp;
	 
	 temp = *a;
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

