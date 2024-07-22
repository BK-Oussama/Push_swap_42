/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_big_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:21:50 by ouboukou@st       #+#    #+#             */
/*   Updated: 2024/07/11 18:37:36 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimized_big_sort(t_list **stack_a, t_list **stack_b)
{
	if (reverse_sorted_percentage(*stack_a) >= 70)
	{
		while (*stack_a)
		{
			push_stack_b(stack_a, stack_b);
		}
		push_back_to_stack_a(stack_a, stack_b);
	}
	else
	{
		big_sort(stack_a, stack_b);
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	*tab;
	int	stack_size;
	int	range;

	stack_size = ft_lstsize(*stack_a);
	tab = sorted_stack_in_tab(stack_a, stack_size);
	if (stack_size <= 100)
		range = 17;
	else
		range = 30;
	push_elements_to_stack_b(stack_a, stack_b, tab, range);
	push_back_to_stack_a(stack_a, stack_b);
	free(tab);
}

void	push_elements_to_stack_b(t_list **stack_a, t_list **stack_b, int *tab,
		int range)
{
	int	stack_size;
	int	i;

	stack_size = ft_lstsize(*stack_a);
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->value <= tab[i])
		{
			push_stack_b(stack_a, stack_b);
			rotate_stack_b(stack_b);
			i++;
		}
		else if (range + i < stack_size && (*stack_a)->value <= tab[range + i])
		{
			push_stack_b(stack_a, stack_b);
			if (ft_lstsize(*stack_b) > 1
				&& (*stack_b)->value <= (*stack_b)->next->value)
				swap_stack_b(stack_b);
			i++;
		}
		else
			rotate_stack_a(stack_a);
	}
}

void	push_back_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	max_elmnt_pos;

	while (*stack_b)
	{
		max_elmnt_pos = max_element_postion(*stack_b);
		if (max_elmnt_pos <= (ft_lstsize(*stack_b) / 2))
		{
			while (max_elmnt_pos > 0)
			{
				rotate_stack_b(stack_b);
				max_elmnt_pos--;
			}
		}
		else
		{
			max_elmnt_pos = ft_lstsize(*stack_b) - max_elmnt_pos;
			while (max_elmnt_pos > 0)
			{
				reverse_rotate_stack_b(stack_b);
				max_elmnt_pos--;
			}
		}
		push_stack_a(stack_a, stack_b);
	}
}

int	reverse_sorted_percentage(t_list *stack)
{
	int		count;
	int		total;
	t_list	*temp;

	count = 0;
	total = ft_lstsize(stack);
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			count++;
		temp = temp->next;
	}
	return ((count * 100) / total);
}
