/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:37:12 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/04/21 17:21:02 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	forking_a(t_philo *phi)
{
	if (phi->id == phi->com->diners)
	{
		pthread_mutex_lock(&phi->m_fork);
		*phi->r_fork = phi->id;
	}
	else
	{
		pthread_mutex_lock(&(phi->prev_phi->m_fork));
		*phi->l_fork = phi->id;
	}
	pst(0, *phi);
}

void	forking_b(t_philo *phi)
{
	if (phi->id == phi->com->diners)
		pthread_mutex_lock(&(phi->prev_phi->m_fork));
	else
		pthread_mutex_lock(&phi->m_fork);
	pst(0, *phi);
}

void	inc_repeat(t_philo *phi)
{
	phi->times_must_eat--;
	phi->com->repeat++;
	if (phi->com->repeat == phi->com->diners * phi->com->rations)
		phi->com->end = phi->id;
}
