/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:00:45 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/05 23:19:08 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void small_sort(t_list **stack_a, t_list **stack_b)
{
	int size;
	
	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;
	else if (size == 2 && check_stack_order(stack_a) == 1)
		swap_stack_a(stack_a);
	else if (size == 3)
		sort_3_number(stack_a);
	else if (size == 4)
		sort_4_number(stack_a, stack_b);
	else if (size == 5)
		sort_5_number(stack_a, stack_b);	
}

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
	int		curent_min_value;
	t_list	*head;
	int		i;
	int		min_postion;

	i = 0;
	min_postion = 0;
	head = *stack_a;
	curent_min_value = head->value;
	while (head)
	{
		if (head->value < curent_min_value)
		{
			curent_min_value = head->value;
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
