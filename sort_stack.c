/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:00:45 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/04 23:26:52 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_number(t_list **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->value;
	middle = (*stack_a)->next->value;
	bottom = (*stack_a)->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
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
