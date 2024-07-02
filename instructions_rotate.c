/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:32:44 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/03 00:32:55 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// Shift UP all elment of stack by 1
int	rotate_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	rotate_stack_a(t_list **stack_a)
{
	if (rotate_stack(stack_a) == 1)
		return (1);
	ft_putendl_fd("ra", 1);
	return (0);
}
int	rotate_stack_b(t_list **stack_b)
{
	if (rotate_stack(stack_b) == 1)
		return (1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rotate_both_stack(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (1);
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}