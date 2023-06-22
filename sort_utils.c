/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:40:14 by ikayacio          #+#    #+#             */
/*   Updated: 2023/06/20 11:42:44 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	if (lst->content > 2147483647
		|| lst->content < -2147483648)
		return (2);
	while (lst->next != NULL)
	{
		if (lst->content > 2147483647
			|| lst->content < -2147483648)
			return (2);
		else if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

long	find_min(t_list *lst)
{
	long	min;

	min = lst->content;
	while (lst != NULL)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

long	find_max(t_list *lst)
{
	long	max;

	max = lst->content;
	while (lst != NULL)
	{
		if (lst ->content > max)
			max = lst -> content;
		lst = lst -> next;
	}
	return (max);
}

int	find_pos(t_list *lst, long num)
{
	int	pos;

	pos = 0;
	while (lst != NULL)
	{
		if (lst->content == num)
			return (pos);
		lst = lst->next;
		pos++;
	}
	return (-1);
}

int	duplicate_check(t_list **a)
{
	t_list	*i;
	t_list	*j;

	i = *a;
	while (i != NULL)
	{
		j = i -> next;
		while (j != NULL)
		{
			if (i -> content == j -> content)
				return (1);
			j = j -> next;
		}
		i = i -> next;
	}
	return (0);
}
