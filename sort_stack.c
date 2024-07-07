/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:00:45 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/07 16:52:29 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_element_to_top(t_list **stack_a, int postion)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	postion = min_element_postion(stack_a);
	if (postion <= stack_size / 2)
	{
		while (postion--)
			rotate_stack_a(stack_a);
	}
	else
	{
		postion = stack_size - postion;
		while (postion--)
			reverse_rotate_stack_a(stack_a);
	}
	
}

int	min_element_postion(t_list **stack_a)
{
	int		current_min_value;
	int		min_postion;
	int		i;
	t_list	*head;

	i = 0;
	min_postion = 0;
	head = *stack_a;
	current_min_value = head->value;
	while (head)
	{
		if (head->value < current_min_value)
		{
			current_min_value = head->value;
			min_postion = i;
		}
		i++;
		head = head->next;
	}
	return (min_postion);
}

void	sort_5_number(t_list **stack_a, t_list **stack_b)
{
	int	position;

	position = min_element_postion(stack_a);
	move_element_to_top(stack_a, position);
	push_stack_b(stack_a, stack_b);
	position = min_element_postion(stack_a);
	move_element_to_top(stack_a, position);
	push_stack_b(stack_a, stack_b);
	sort_3_number(stack_a);
	push_stack_a(stack_a, stack_b);
	push_stack_a(stack_a, stack_b);
}

void	sort_4_number(t_list **stack_a, t_list **stack_b)
{
	int	position;

	position = min_element_postion(stack_a);
	move_element_to_top(stack_a, position);
	push_stack_b(stack_a, stack_b);
	
	sort_3_number(stack_a);
	push_stack_a(stack_a, stack_b);
}

void	sort_3_number(t_list **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->value;
	middle = (*stack_a)->next->value;
	bottom = (*stack_a)->next->next->value;
	if (check_stack_order(stack_a) == 0)
		return ;
	else if (top > middle && middle < bottom && top < bottom)
		swap_stack_a(stack_a);
	else if (top > middle && middle > bottom && top > bottom)
	{
		swap_stack_a(stack_a);
		reverse_rotate_stack_a(stack_a);
	}
	else if (top > middle && middle < bottom && top > bottom)
		rotate_stack_a(stack_a);
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap_stack_a(stack_a);
		rotate_stack_a(stack_a);
	}
	else if (top < middle && middle > bottom && top > bottom)
		reverse_rotate_stack_a(stack_a);
}
