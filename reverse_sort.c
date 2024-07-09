/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou@student.42.fr <ouboukou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:21:50 by ouboukou@st       #+#    #+#             */
/*   Updated: 2024/07/09 01:26:28 by ouboukou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int reverse_sorted_percentage(t_list *stack)
{
    int count = 0;
    int total = ft_lstsize(stack);
    t_list *temp = stack;

    while (temp && temp->next)
    {
        if (temp->value > temp->next->value)
            count++;
        temp = temp->next;
    }

    return ((count * 100) / total);
}

// int is_reverse_sorted(t_list *stack)
// {
//     t_list *temp = stack;
//     while (temp && temp->next)
//     {
//         if (temp->value < temp->next->value)
//             return (0);
//         temp = temp->next;
//     }
//     return (1);
// }


void optimized_reverse_sort(t_list **stack_a, t_list **stack_b)
{
    if (reverse_sorted_percentage(*stack_a) >= 70) // Threshold can be adjusted
    {
        while (*stack_a)
        {
            push_stack_b(stack_a, stack_b);
        }
        push_back_to_stack_a(stack_a, stack_b);
        
    }
    else
    {
        big_sort(stack_a, stack_b); // Fall back to the original algorithm
    }
}


