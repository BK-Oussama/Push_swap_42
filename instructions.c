/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou@student.42.fr <ouboukou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 05:29:19 by ouboukou@st       #+#    #+#             */
/*   Updated: 2024/06/28 12:56:24 by ouboukou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// swap the first two elments of stack a or b or both

int swap(t_list **stack)
{
    t_list *head;
    t_list *next;
    int temp_value;
    int temp_index;
    
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

int swap_stack_a(t_list **stack_a)
{
    if (swap(stack_a) == 1)
        return 1;
    ft_putendl_fd("sa", 1);
    return (0);
}

int swap_stack_b(t_list **stack_b)
{
    if (swap(stack_b) == 1)
        return (1);
    ft_putendl_fd("sb", 1);
    return (0);
}

int swap_both_stack(t_list **stack_a, t_list **stack_b)
{
    if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
        return 1;
    swap(stack_a);
    swap(stack_b);
    ft_putendl_fd("ss", 1);
    return 0;
}


// Move the top element of a stack, to either stack a or stack b

int push(t_list **dest_stack, t_list **src_stack)
{
    t_list *tmp;
    t_list *dest_head;
    t_list *src_head;

    if (ft_lstsize(*src_stack) == 0)
    {
        ft_putstr_fd("Push Error: src stack is empty", 1);
        return (1);
    }
    
    dest_head = *dest_stack; 
    src_head = *src_stack;  // Update source stack head

    tmp = src_head;
    
    src_head = src_head->next;  // Move source head to the next element
    *src_stack = src_head;      // Update source stack head
    
    if (!dest_head)
    {
        dest_head = tmp;
        dest_head->next = NULL;
        *dest_stack = dest_head;
    }
    else
    {
        tmp->next = dest_head;  // Link new elment to current head
        *dest_stack = tmp;      // Update destination stck head
    }

    return (0);
}

int push_stack_a(t_list **stack_a, t_list **stack_b)
{
    if (push(stack_a, stack_b) == 1)
        return (1);
    ft_putendl_fd("pa", 1);
        return (0);
}

int push_stack_b(t_list **stack_a, t_list **stack_b)
{
    if (push(stack_b, stack_a) == 1)
        return (1);
    ft_putendl_fd("pa", 1);
        return (0);
}
int rotate_stack(t_list **stack)
{
    t_list *head;
    t_list *tail;
    
    if (ft_lstsize(*stack) < 2)
        return (1);

    head = *stack;
    tail = ft_lstlast(head);
    *stack = head->next;
    head->next = NULL;
    tail->next = head; 
    return (0);
}

int rotate_stack_a(t_list **stack_a)
{
    if (rotate_stack(stack_a) == 1)
        return (1);
    ft_putendl_fd("ra", 1);
    return (0);
}
int rotate_stack_b(t_list **stack_b)
{
    if (rotate_stack(stack_b) == 1)
        return (1);
    ft_putendl_fd("rb", 1);
    return (0);
}

int rotate_both_stack(t_list **stack_a, t_list **stack_b)
{
    if((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
        return (1);

    rotate_stack(stack_a);
    rotate_stack(stack_b);
    ft_putendl_fd("rr", 1);
    return 0;
}

int reverse_rotate_stack(t_list **stack)
{
    t_list *head;
    t_list *tail;
    
    if (ft_lstsize(*stack) < 2)
        return (1);
    
    head = *stack;
    tail = ft_lstlast(head);

    // Traverse to find the second last element
    while (head->next->next != NULL)
    {
        head = head->next;
    }
    // Detach the last element
    head->next = NULL;

    tail->next = *stack;
    *stack = tail;

    return (0);
}

int reverse_rotate_stack_a(t_list **stack_a)
{
    if (reverse_rotate_stack(stack_a) == 1)
        return (1);

    ft_putendl_fd("rra", 1);
    return (0);
}

int reverse_rotate_stack_b(t_list **stack_b)
{
    if (reverse_rotate_stack(stack_b) == 1)
        return (1);
    ft_putendl_fd("rrb", 1);
    return 0;
}

int reverse_rotate_both_stack(t_list **stack_a, t_list **stack_b)
{
    if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
        return (1);
    reverse_rotate_stack(stack_a);
    reverse_rotate_stack(stack_b);
    ft_putendl_fd("rrr", 1);
    return (0);
}