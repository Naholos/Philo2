/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:06:03 by aoteo-be          #+#    #+#             */
/*   Updated: 2021/09/21 16:47:32 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

static int	compute_value(const char *nptr, int i, int sign)
{
	long	value;

	value = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = (value * 10) + (nptr[i] - '0');
		if (value > 2147483647 && sign == 1)
			return (-1);
		if (value > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return ((int)value * sign);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((nptr[i] == ' ') || (nptr[i] == '\f') || (nptr[i] == '\n')
		|| (nptr[i] == '\r') || (nptr[i] == '\t') || (nptr[i] == '\v'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	return (compute_value(nptr, i, sign));
}
