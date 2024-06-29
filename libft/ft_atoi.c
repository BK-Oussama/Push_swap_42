/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:21:19 by ouboukou          #+#    #+#             */
/*   Updated: 2024/06/29 22:30:10 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


long	ft_atoi(const char *str)
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
		if (rslt > 2147483647 && sign == 1)
			return (2147483648);
		else if (rslt > 2147483648 && sign == -1)
			return (-2147483648);
		i++;
	}
	return (rslt * sign);
}
