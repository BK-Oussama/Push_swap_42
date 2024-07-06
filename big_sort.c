/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:45:50 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/07 00:32:32 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// write a function that check the max num position

int	bigest_num_in_stack(t_list *stack_a)
{
	int		b;
	int		order;
	int		i;
	t_list	*temp_a;

	i = 1;
	temp_a = stack_a;
	b = temp_a->value;
	while (temp_a)
	{
		if (temp_a->value > b)
		{
			b = temp_a->value;
			order = i;
		}
		temp_a = temp_a->next;
		i++;
	}
	return (order);
}

void	half_sort_stack_b(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		*tab;
	t_list	*temp;
	int		j;
	int		size;
	int		len;
	int		range;
	int		cost;

	i = 0;
	tab = malloc(sizeof(int) * ft_lstsize(*stack_a));
	temp = *stack_a;
	j = 0;
	while (temp)
	{
		tab[j] = temp->value;
		temp = temp->next;
		j++;
	}
	tab = order(ft_lstsize(*stack_a), tab);
	size = ft_lstsize(*stack_a);
	len = ft_lstsize(*stack_a);
	if (len <= 100)
		range = 17;
	else
		range = 30;
   //-------------------------------------the algo how to push from stuck a to b using the rang --------------------------------------------
	while (*stack_a)
	{
		if ((*stack_a)->value <= tab[i])
		{
			push_stack_b(stack_a, stack_b);
			rotate_stack_b(stack_b);
			i++;
		}
		else if (i + range < size && (*stack_a)->value <= tab[i + range])
		{
			push_stack_b(stack_a, stack_b);
			if (ft_lstsize(*stack_b) > 1
				&& (*stack_b)->value <= (*stack_b)->next->value)
			{
				swap_stack_b(stack_b);
			}
			i++;
		}
		else
			rotate_stack_a(stack_a);
	}
    //-------------------------push evrey time the biggest number to stuck a for example 100 then 99 then 98 ... ------------------------------------- 
	while (*stack_b)
	{
		i = bigest_num_in_stack(*stack_b);
		if (i <= (ft_lstsize(*stack_b) / 2) + 1)
		{
			cost = i - 1;
			while (cost > 0)
			{
				rotate_stack_b(stack_b);
				cost--;
			}
		}
		else
		{
			cost = ft_lstsize(*stack_b) - i + 1;
			while (cost > 0)
			{
				reverse_rotate_stack_b(stack_b);
				cost--;
			}
		}
		push_stack_a(stack_a, stack_b);
	}
}

int	*order(int size, int *tab)
{
	int i;
	int j;
	int b;

	i = 0;
	int len = size;
	while (i < len)
	{
		j = 0;
		while ((i + j) < len)
		{
			if (tab[i] > tab[i + j])
			{
				b = tab[i];
				tab[i] = tab[i + j];
				tab[i + j] = b;
			}
			j++;
		}
		i++;
	}
	i = 0;
	return (tab);
}