/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:37:12 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/04/21 17:13:51 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	clean_input(t_input *input)
{
	if (input->diners == 0)
	{
		free (input);
		return (0);
	}
	return (-1);
}

int	free_all(t_philo *phi, int *forks, t_input *input)
{
	int	i;

	if (phi->com->diners > 0)
	{
		i = -1;
		while (++i < phi->com->diners)
			pthread_mutex_destroy(&phi->m_fork);
		pthread_mutex_destroy(&phi->com->m_print);
		pthread_mutex_destroy(&phi->com->m_print);
	}
	free(input);
	free(forks);
	free(phi);
	return (0);
}

int	manage_memory(t_philo *phi, int *forks, t_input *input)
{
	if (phi != NULL && forks != NULL)
	{
		memset(forks, 0, input->diners * sizeof(int));
		return (0);
	}
	if (phi == NULL)
		free(phi);
	if (forks == NULL)
		free(forks);
	free (input);
	return (1);
}
