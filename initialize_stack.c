/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:20:50 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/01 21:47:58 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int check_duplicates(t_list *stack)
{
	t_list *current;
	t_list *traversal;
	
	if (NULL == stack || NULL == stack->next)
		return (1); 
		// handle error more carfully here
	
	current = stack;
	while (current != NULL)
	{
		traversal = current->next;
		while (traversal != NULL)
		{
			if (current->value == traversal->value)
				return (1); // or print message and exit directly!
			traversal = traversal->next;
		}
		current = current->next;
	}
	return (0);
}
void	free_stack(t_list **stack)
{
	t_list	*head;

	if (NULL == stack || NULL == *stack)
		return ;
	head = *stack;
	while (*stack)
	{
		head = (*stack)->next;
		free(*stack);
		*stack = head;
	}
	*stack = NULL;
}
int	initialize_stack(char **argv, t_list **stack_a)
{
	int		i;
	t_list	*new_node;
			char **args;
	int		k;

	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' ') == NULL)
		{
			if ((new_node = ft_lstnew(ft_atoi(argv[i]))) == NULL)
				ft_error("Error ocuerd while creating node!");
			ft_lstadd_back(stack_a, new_node);
			// i should here free the node after it is in the staclk!!
			// free(new_node);
		}
		else
		{
			args = ft_split(argv[i], ' ');
			if (args == NULL)
				ft_error("Split Failed!");
			k = 0;
			while (args[k])
			{
				if ((new_node = ft_lstnew(ft_atoi(args[k]))) == NULL)
					ft_error("Error ocuerd while creating node!");
				ft_lstadd_back(stack_a, new_node);
				k++;
			}
			ft_free(args);
		}
		i++;
	}
	return (0);
}
