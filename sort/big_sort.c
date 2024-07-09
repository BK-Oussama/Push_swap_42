/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou@student.42.fr <ouboukou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:45:50 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/09 03:15:50 by ouboukou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// write a function that check the max num max_postion

int	*sorted_stack_in_tab(t_list **stack_a, int stack_size)
{
	int		*tab;
	t_list	*head;
	int		i;

	tab = malloc(sizeof(int) * stack_size);
	if (!tab)
		ft_error("Error: malloc failed");
	head = *stack_a;
	i = 0;
	while (head)
	{
		tab[i] = head->value;
		head = head->next;
		i++;
	}
	tab = bubble_sort(tab, stack_size);
	return (tab);
}

int	*bubble_sort(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

int	max_element_postion(t_list *stack_a)
{
	int		current_max_value;
	int		max_postion;
	int		i;
	t_list	*head;

	i = 0;
	head = stack_a;
	current_max_value = head->value;
	while (head)
	{
		if (head->value > current_max_value)
		{
			current_max_value = head->value;
			max_postion = i;
		}
		head = head->next;
		i++;
	}
	return (max_postion);
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	*tab;
	int	stack_size;
	int	range;

	stack_size = ft_lstsize(*stack_a);
	tab = sorted_stack_in_tab(stack_a, stack_size);
	if (stack_size <= 100)
		range = 17;
	else
		range = 30;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->value <= tab[i])
		{
			push_stack_b(stack_a, stack_b);
			rotate_stack_b(stack_b);
			i++;
		}
		else if (i + range < stack_size && (*stack_a)->value <= tab[i + range])
		{
			push_stack_b(stack_a, stack_b);
			if (ft_lstsize(*stack_b) > 1
				&& (*stack_b)->value <= (*stack_b)->next->value)
				swap_stack_b(stack_b);
			i++;
		}
		else
			rotate_stack_a(stack_a);
	}
	// ---------push evrey time the biggest number to stack a for example 100 then 99 then 98.. -----------
	push_back_to_stack_a(stack_a, stack_b);
}
void	push_back_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	max_elmnt_postion;

	while (*stack_b)
	{
		max_elmnt_postion = max_element_postion(*stack_b);
		if (max_elmnt_postion <= (ft_lstsize(*stack_b) / 2))
		{
			while (max_elmnt_postion > 0)
			{
				rotate_stack_b(stack_b);
				max_elmnt_postion--;
			}
		}
		else
		{
			max_elmnt_postion = ft_lstsize(*stack_b) - max_elmnt_postion;
			while (max_elmnt_postion > 0)
			{
				reverse_rotate_stack_b(stack_b);
				max_elmnt_postion--;
			}
		}
		push_stack_a(stack_a, stack_b);
	}
}
