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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
	{
		ft_putendl_fd("Error: Please Enter an array of numbers!", 2);
		return (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (check_arguments(argv) == 0)
		{
			printf("main: Good input\n");
			initialize_stack(argv, &stack_a);

			if (check_duplicates(stack_a) == 0)
				printf("Stack Unique.\n");
			else 
				printf("Stack has duplicates\n");
				
			if (check_stack_order(stack_a) == 1)
				printf("stack need to be sorted!\n");
			else
				printf("stack is sorted!\n");

			t_list	*head;
			head = stack_a;
			while (head != NULL)
			{
				printf("%d\n", head->value);
				head = head->next;
			}
			printf("After sorting\n");
			if (ft_lstsize(stack_a) == 3)
				sort_3_number(&stack_a);
			t_list *head___ = stack_a;
			while (head___ != NULL)
			{
				printf("%d\n", head___->value);
				head___ = head___->next;
			}
		}
		else
			printf("main: Bad input\n");
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}




























