/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:37:12 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/04/21 17:13:51 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

static void	free_bi_array(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}

static int	checking_errors(char **data, int msg)
{
	if (msg == 0)
		printf("Error: only positive decimal parameters allowed.");
	else
		printf("Error: only 4 or 5 input parameters allowed.");
	free_bi_array(data);
	return (-1);
}

static int	checking_input(char *sliced_data[])
{
	int	i;
	int	j;

	i = -1;
	while (sliced_data[++i])
	{
		j = -1;
		while (sliced_data[i][++j])
		{
			if (j == 0 && sliced_data[i][j] == '+')
				continue ;
			else if (sliced_data[i][j] < '0' || sliced_data[i][j] > '9')
				return (checking_errors(sliced_data, 0));
		}
	}
	if (i < 4 || i > 5)
		return (checking_errors(sliced_data, 1));
	return (0);
}

static int	get_data(char **sliced_data, t_input *input)
{
	int		i;

	i = 0;
	while (sliced_data[i])
		i++;
	input->init = get_time_ms();
	input->end = 0;
	input->diners = ft_atoi(sliced_data[0]);
	input->time_to_die = ft_atoi(sliced_data[1]);
	input->time_to_eat = ft_atoi(sliced_data[2]);
	input->time_to_sleep = ft_atoi(sliced_data[3]);
	input->rations = -1;
	if (i == 5)
		input->rations = ft_atoi(sliced_data[4]);
	input->repeat = 0;
	free_bi_array(sliced_data);
	if (input->diners > 200 || input->time_to_die < 60
		|| input->time_to_sleep < 60 || input->time_to_eat < 60)
	{
		printf("Error. Parameters out of range.");
		return (-1);
	}
	pthread_mutex_init(&input->m_print, NULL);
	pthread_mutex_init(&input->m_death, NULL);
	return (0);
}

int	parse_input(int argc, char *argv[], t_input *input)
{
	char	*data;
	char	*data_copy;
	char	**sliced_data;
	int		i;

	data = ft_strdup("");
	i = 1;
	while (i <= argc - 1)
	{
		data_copy = data;
		data = ft_strjoin(data, argv[i]);
		free(data_copy);
		data_copy = data;
		data = ft_strjoin(data, " ");
		free(data_copy);
		i++;
	}
	sliced_data = ft_split(data, ' ');
	free(data);
	if (checking_input(sliced_data) || get_data(sliced_data, input))
		return (-1);
	else
		return (0);
}
