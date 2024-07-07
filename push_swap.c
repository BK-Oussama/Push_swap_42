/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:26:25 by ouboukou          #+#    #+#             */
/*   Updated: 2024/06/29 17:55:19 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void print_stack(t_list **stack)
// {
// 	t_list *head;
	
// 	head = *stack;
// 	while (head)
// 	{
// 		printf("%d\n", head->value);
// 		head = head->next;
// 	}
// }

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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (1);

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (check_arguments(argv) == 0)
		{
			initialize_stack(argv, &stack_a);
			if (ft_lstsize(stack_a) < 2)
				return (1);
			if (check_duplicates(stack_a) == 1)
				ft_error("Error: Duplicate Numbers");
			if (check_stack_order(&stack_a) == 0)
				return (1);
			
			// print_stack(&stack_a);
			if (ft_lstsize(stack_a) <= 5)
				small_sort(&stack_a, &stack_b);
				
			if (ft_lstsize(stack_a) > 5)
			{
				big_sort(&stack_a, &stack_b);
			}
			// print_stack(&stack_a);
		}
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}




























