/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:00:45 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/05 00:57:20 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void    sort_5_number(t_list **stack_a, t_list **stack_b)
{
    
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



























void sort_five_numbers(t_list **stack_a, t_list **stack_b)
{
    // Step 1: Move the two smallest numbers to stack B
    move_smallest_to_b(stack_a, stack_b);
    move_smallest_to_b(stack_a, stack_b);

    // Step 2: Sort the remaining three numbers in stack A
    sort_three_numbers(stack_a);

    // Step 3: Push the numbers back from stack B to stack A
    pa(stack_a, stack_b); // Push from stack B to stack A
    pa(stack_a, stack_b); // Push from stack B to stack A
}

void move_smallest_to_b(t_list **stack_a, t_list **stack_b)
{
    int min_pos = find_min_position(stack_a);
    move_to_top(stack_a, min_pos);
    pb(stack_a, stack_b); // Push from stack A to stack B
}

int find_min_position(t_list **stack)
{
    int min_value = (*stack)->value;
    int min_pos = 0;
    int pos = 0;
    t_list *temp = *stack;

    while (temp)
    {
        if (temp->value < min_value)
        {
            min_value = temp->value;
            min_pos = pos;
        }
        pos++;
        temp = temp->next;
    }
    return min_pos;
}

void move_to_top(t_list **stack, int pos)
{
    int size = ft_lstsize(*stack);
    if (pos <= size / 2)
    {
        while (pos--)
            ra(stack); // Rotate
    }
    else
    {
        pos = size - pos;
        while (pos--)
            rra(stack); // Reverse rotate
    }
}

void sort_three_numbers(t_list **stack)
{
    // Implement your 3 number sort logic here
}

// Assume ra, rra, pb, pa, and other helper functions are implemented
