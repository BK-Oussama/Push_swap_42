/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hhhhhhhhhhhhhhhhhhhhh.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:53:39 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/07 17:20:16 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *sorted_stack_in_tab(t_list **stack_a, int stack_size)
{
        int *tab;
        t_list *head;
        int i;
        
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
        tab[i] == NULL; // think about it!!
        tab = bubble_sort(tab, stack_a);
        return (tab);
}
