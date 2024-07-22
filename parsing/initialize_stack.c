/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:20:50 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/10 16:18:13 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_list *stack)
{
	t_list	*current;
	t_list	*traversal;

	if (NULL == stack || NULL == stack->next)
		return (3);
	current = stack;
	while (current != NULL)
	{
		traversal = current->next;
		while (traversal != NULL)
		{
			if (current->value == traversal->value)
				return (1);
			traversal = traversal->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_stack_order(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (1);
		head = head->next;
	}
	return (0);
}

void	initialize_stack(char **argv, t_list **stack_a)
{
	int		i;
	t_list	*new_node;

	i = 1;
	while (argv[i])
	{
		if (NULL == ft_strchr(argv[i], ' '))
		{
			new_node = ft_lstnew(ft_atoi(argv[i]));
			if (NULL == new_node)
				ft_error("Error");
			ft_lstadd_back(stack_a, new_node);
		}
		else
			initialize_stack_1(argv, i, stack_a);
		i++;
	}
	if (ft_lstsize(*stack_a) < 2)
	{
		free_stack(stack_a);
		exit (EXIT_SUCCESS);
	}
}

void	initialize_stack_1(char **argv, int index, t_list **stack_a)
{
	int		i;
	char	**args;
	t_list	*new_node;

	args = ft_split(argv[index], ' ');
	if (NULL == args)
		ft_error("Error");
	i = 0;
	while (args[i])
	{
		new_node = ft_lstnew(ft_atoi(args[i]));
		if (NULL == new_node)
			ft_error("Error");
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	ft_free(args);
}
