/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:04:45 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/09 17:18:01 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int		stack_is_empty(t_list **stack)
{
    if (*stack == NULL || stack == NULL)
        return (1);
    else
        return (0);
}

void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
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

void 	print_stack(t_list **stack)
{
	t_list *head;

	head = *stack;
	while (head)
	{
		printf("%d\n", head->value);
		head = head->next;
	}
}

void free_stack_and_exit(t_list **stack, char *msg)
{
	free_stack(stack);
	ft_error(msg);
}
