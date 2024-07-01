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

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        ft_putendl_fd("Error: Please Enter an array of numbers!", 2);
        return (1);
    }
    t_list *stack_a;

    stack_a = NULL;
    if (argc >= 2)
    {
        if (check_arguments(argv) == 0)
        {
            printf("main: Good input\n");
            initialize_stack(argv, &stack_a);
            t_list *head = stack_a;
            while (head != NULL)
            {
                printf("%d\n", head->value);
                head = head->next;
            }
        }
        else
            printf("main: Bad input\n");
    }
    return (0);
}
