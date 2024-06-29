/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maina.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:26:50 by ouboukou          #+#    #+#             */
/*   Updated: 2024/06/29 22:17:33 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	rslt;

	i = 0;
	sign = 1;
	rslt = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while ((str[i] != '\0' && str[i] >= '0' && str[i] <= '9'))
	{
		rslt = rslt * 10 + (str[i] - '0');
		if (rslt > 9223372036854775807 / 10 && sign == 1)
			return (-1);
		else if (rslt > 9223372036854775807 / 10 && sign == -1)
			return (0);
		i++;
	}
	return (rslt * sign);
}

int main()
{
    int n;    
    printf("%d\n", atoi("214748364799"));
    printf("%d\n", ft_atoi("214748364799"));

    printf("\n%d", atoi("-214748364899"));
    printf("\n%d", ft_atoi("-214748364899"));
    
    printf("\n%d", atoi("-214748364811"));
    printf("\n%d", ft_atoi("-214748364811"));


    return 0;
}