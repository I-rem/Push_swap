/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:37:25 by ikayacio          #+#    #+#             */
/*   Updated: 2023/06/20 11:39:47 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_index(t_list **a)	
{
	int		index;
	int		min;
	t_list	*temp;
	
	temp = *a;
	index = 0;
	min = find_min2(*a, index);
	
	while (min != 0)
	{
		while (temp -> content != min && temp != NULL)
			temp = temp -> next;
		if (temp != NULL)
		{
			index++;
			temp -> content = index;
			temp = *a;
		}
		min = find_min2(*a, index);;
	}
	write(1, "test", 4);
}

void	make_positive(t_list **a)
{
	t_list	*temp;
	int		min;

	min = find_min(*a);
	temp = *a;
	while (temp)
	{
		temp -> content -= min;
		temp = temp -> next;
	}
	make_index(a);
}

void	right_shift(t_list **a)
{
	t_list	*temp;

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

int	all_zero(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp)
	{
		if (temp -> content != 0)
			return (0);
		temp = temp -> next;
	}
	return (1);
}
