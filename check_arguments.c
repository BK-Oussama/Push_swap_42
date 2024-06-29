/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:10:26 by ouboukou          #+#    #+#             */
/*   Updated: 2024/06/29 22:21:04 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	validate_number(const char *str)
{
	int			i;
	int long	num;

	if (str[0] == '\0')
	{
		ft_putendl_fd("Error: empty string", 2);
		return (1);
	}
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			return (1);
		i++;
	}
	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_putstr_fd("Error: Number is out of integer range\n", 2);
		return (1);
	}
	return (0);
}

int	check_single_number(const char *arg)
{
	if (validate_number(arg) == 1)
	{
		ft_putendl_fd("Error: invalid number", 2);
		return (1);
	}
	return (0);
}

int	check_multiple_numbers(const char *arg)
{
	char	**args;
	int		k;

	args = ft_split(arg, ' ');
	if (args == NULL)
	{
		ft_putendl_fd("Split Failed!", 2);
		return (0);
		// till you edit this line with error and exit function form pipex!!
	}
	k = 0;
	while (args[k])
	{
		if (validate_number(args[k]) == 1)
		{
			ft_putendl_fd("Error: invalid number", 2);
			ft_free(args);
			return (1);
		}
		k++;
	}
	ft_free(args);
	return (0);
}

int	check_arguments(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' ') == NULL)
		{
			if (check_single_number(argv[i]) == 1)
				return (1);
		}
		else
		{
			if (check_multiple_numbers(argv[i]) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}
