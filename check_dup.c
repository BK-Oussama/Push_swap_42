/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:20:50 by ouboukou          #+#    #+#             */
/*   Updated: 2024/06/29 23:21:37 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	has_duplicates(int arr[], int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
			{
				return (1); // Duplicate found
			}
			j++;
		}
		i++;
	}
	return (0); // No duplicates found
}

int	main(void)
{
	int	arr[] ={1, 2, 3, 4, 2};
	int	size;

	size = sizeof(arr) / sizeof(arr[0]);
	if (has_duplicates(arr, size))
	{
		printf("Array contains duplicates\n");
	}
	else
	{
		printf("Array does not contain duplicates\n");
	}
	return (0);
}
