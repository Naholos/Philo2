/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:06:03 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/04/21 16:39:28 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	time_stm(void)
{
	static long		timebase;

	if (timebase == 0)
		timebase = get_time_ms();
	return (get_time_ms() - timebase);
}

void	ft_sleep(long ms)
{
	long	start;

	start = get_time_ms();
	while ((get_time_ms() - start) < ms)
		usleep(50);
}

void	pst(int st, t_philo phi)
{
	pthread_mutex_lock(&phi.com->m_print);
	if (st == 0)
		printf("\x1b[36m""%lu ms, %d has taken a fork.\n", time_stm(), phi.id);
	else if (st == 1)
		printf("\x1b[32m""%lu ms, %d is eating.\n", time_stm(), phi.id);
	else if (st == 2 && phi.com->repeat != phi.com->diners * phi.com->rations)
		printf("\x1b[33m""%lu ms, %d is sleeping.\n", time_stm(), phi.id);
	else if (st == 3 && phi.com->repeat != phi.com->diners * phi.com->rations)
		printf("\x1b[34m""%lu ms, %d is thinking.\n", time_stm(), phi.id);
	else if (st == 4 && phi.com->repeat != phi.com->diners * phi.com->rations)
		printf("\x1b[31m""%lu ms, %d has died.\n", time_stm(), phi.id);
	if (st != 4)
		pthread_mutex_unlock(&phi.com->m_print);
}
