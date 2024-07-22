/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:33:52 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/10 20:56:22 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head->next->next != NULL)
	{
		head = head->next;
	}
	head->next = NULL;
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	reverse_rotate_stack_a(t_list **stack_a)
{
	if (reverse_rotate_stack(stack_a) == 1)
		return (1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	reverse_rotate_stack_b(t_list **stack_b)
{
	if (reverse_rotate_stack(stack_b) == 1)
		return (1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	reverse_rotate_both_stack(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (1);
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
