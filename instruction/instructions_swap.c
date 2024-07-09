/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 05:29:19 by ouboukou@st       #+#    #+#             */
/*   Updated: 2024/07/03 00:33:57 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the first two elments of stack a or b or both

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		temp_value;
	int		temp_index;

	if (ft_lstsize(*stack) < 2)
	{
		ft_putstr_fd("Swap Error", 1);
		return (1);
	}
	head = *stack;
	next = head->next;
	temp_value = head->value;
	temp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = temp_value;
	next->index = temp_index;
	return (0);
}

int	swap_stack_a(t_list **stack_a)
{
	if (swap(stack_a) == 1)
		return (1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	swap_stack_b(t_list **stack_b)
{
	if (swap(stack_b) == 1)
		return (1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	swap_both_stack(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
