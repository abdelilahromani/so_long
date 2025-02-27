/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:20:03 by aromani           #+#    #+#             */
/*   Updated: 2025/02/20 22:36:34 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	checker(long n, int sig, char c)
{
	if ((n > 922337203685477580
			|| (n == 922337203685477580 && c > 7)) && sig == 1)
		return (-1);
	if ((n > 922337203685477580
			|| (n == 922337203685477580 && c > 7)) && sig == -1)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sig;
	long	num;

	i = 0;
	sig = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - 48;
		i++;
		if (checker(num, sig, str[i]) != 1)
			return (checker(num, sig, str[i]));
	}
	return ((int)(num * sig));
}
