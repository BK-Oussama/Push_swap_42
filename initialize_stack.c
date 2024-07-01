/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:20:50 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/01 18:35:40 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int initialize_stack(char **argv, t_list **stack_a)
{
	int i;
	t_list *new_node;
	
	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' ') == NULL)
		{
			if ((new_node = ft_lstnew(ft_atoi(argv[i]))) == NULL)
				ft_error("Error ocuerd while creating node!");
			ft_lstadd_front(stack_a, new_node);
			// i should here free the node after it is in the staclk!!
		}
		else
		{
			char **args;
			args = ft_split(argv[i], ' ');
			if (args == NULL)
				ft_error("Split Failed!");
			
			int k = 0;
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
	return 0;
}









// int	has_duplicates(int arr[], int n)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < n - 1)
// 	{
// 		j = i + 1;
// 		while (j < n)
// 		{
// 			if (arr[i] == arr[j])
// 			{
// 				return (1); // Duplicate found
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0); // No duplicates found
// }

// int	main(void)
// {
// 	int	arr[] ={1, 2, 3, 4, 2};
// 	int	size;

// 	size = sizeof(arr) / sizeof(arr[0]);
// 	if (has_duplicates(arr, size))
// 	{
// 		printf("Array contains duplicates\n");
// 	}
// 	else
// 	{
// 		printf("Array does not contain duplicates\n");
// 	}
// 	return (0);
// }
